// Copyright (c) 2020, Samsung Research America
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License. Reserved.

#include <string>
#include <memory>
#include <vector>
#include <limits>
#include <algorithm>

#include "my_nav2_smac_planner/my_smac_planner_2d.hpp"
#include "nav2_util/geometry_utils.hpp"

// #define BENCHMARK_TESTING

namespace my_nav2_smac_planner
{
using namespace std::chrono;  // NOLINT
using rcl_interfaces::msg::ParameterType;
using std::placeholders::_1;

MySmacPlanner2D::MySmacPlanner2D()
: _a_star(nullptr),
  _collision_checker(nullptr, 1, nullptr),
  _smoother(nullptr),
  _costmap(nullptr),
  _costmap_downsampler(nullptr)
{
}

MySmacPlanner2D::~MySmacPlanner2D()
{
  RCLCPP_INFO(
    _logger, "Destroying plugin %s of type MySmacPlanner2D",
    _name.c_str());
}

void MySmacPlanner2D::configure(
  const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
  std::string name, std::shared_ptr<tf2_ros::Buffer>/*tf*/,
  std::shared_ptr<nav2_costmap_2d::Costmap2DROS> costmap_ros)
{
  _node = parent;
  auto node = parent.lock();
  _logger = node->get_logger();
  _clock = node->get_clock();
  _costmap = costmap_ros->getCostmap();
  _name = name;
  _global_frame = costmap_ros->getGlobalFrameID();

  RCLCPP_INFO(_logger, "Configuring %s of type MySmacPlanner2D", name.c_str());

  // General planner params
  nav2_util::declare_parameter_if_not_declared(
    node, name + ".tolerance", rclcpp::ParameterValue(0.125));
  _tolerance = static_cast<float>(node->get_parameter(name + ".tolerance").as_double());
  nav2_util::declare_parameter_if_not_declared(
    node, name + ".downsample_costmap", rclcpp::ParameterValue(false));
  node->get_parameter(name + ".downsample_costmap", _downsample_costmap);
  nav2_util::declare_parameter_if_not_declared(
    node, name + ".downsampling_factor", rclcpp::ParameterValue(1));
  node->get_parameter(name + ".downsampling_factor", _downsampling_factor);
  nav2_util::declare_parameter_if_not_declared(
    node, name + ".cost_travel_multiplier", rclcpp::ParameterValue(1.0));
  node->get_parameter(name + ".cost_travel_multiplier", _search_info.cost_penalty);

  nav2_util::declare_parameter_if_not_declared(
    node, name + ".allow_unknown", rclcpp::ParameterValue(true));
  node->get_parameter(name + ".allow_unknown", _allow_unknown);
  nav2_util::declare_parameter_if_not_declared(
    node, name + ".max_iterations", rclcpp::ParameterValue(1000000));
  node->get_parameter(name + ".max_iterations", _max_iterations);
  nav2_util::declare_parameter_if_not_declared(
    node, name + ".max_on_approach_iterations", rclcpp::ParameterValue(1000));
  node->get_parameter(name + ".max_on_approach_iterations", _max_on_approach_iterations);
  nav2_util::declare_parameter_if_not_declared(
    node, name + ".use_final_approach_orientation", rclcpp::ParameterValue(false));
  node->get_parameter(name + ".use_final_approach_orientation", _use_final_approach_orientation);

  nav2_util::declare_parameter_if_not_declared(
    node, name + ".max_planning_time", rclcpp::ParameterValue(2.0));
  node->get_parameter(name + ".max_planning_time", _max_planning_time);

  //_downsample_costmap = true;
  //_downsampling_factor = 4;

  _motion_model = MotionModel::TWOD;

  if (_max_on_approach_iterations <= 0) {
    RCLCPP_INFO(
      _logger, "On approach iteration selected as <= 0, "
      "disabling tolerance and on approach iterations.");
    _max_on_approach_iterations = std::numeric_limits<int>::max();
  }

  if (_max_iterations <= 0) {
    RCLCPP_INFO(
      _logger, "maximum iteration selected as <= 0, "
      "disabling maximum iterations.");
    _max_iterations = std::numeric_limits<int>::max();
  }

  // Initialize collision checker
  _collision_checker = GridCollisionChecker(_costmap, 1 /*for 2D, most be 1*/, node);
  _collision_checker.setFootprint(
    costmap_ros->getRobotFootprint(),
    true /*for 2D, most use radius*/,
    0.0 /*for 2D cost at inscribed isn't relevent*/);

  // Initialize A* template
  _a_star = std::make_unique<AStarAlgorithm<Node2D>>(_motion_model, _search_info);
  _a_star->initialize(
    _allow_unknown,
    _max_iterations,
    _max_on_approach_iterations,
    _max_planning_time,
    0.0 /*unused for 2D*/,
    1.0 /*unused for 2D*/);

  // Initialize path smoother
  SmootherParams params;
  params.get(node, name);
  params.holonomic_ = true;  // So smoother will treat this as a grid search
  _smoother = std::make_unique<Smoother>(params);
  _smoother->initialize(1e-50 /*No valid minimum turning radius for 2D*/);

  // Initialize costmap downsampler
  if (_downsample_costmap && _downsampling_factor > 1) {
    std::string topic_name = "downsampled_costmap";
    _costmap_downsampler = std::make_unique<CostmapDownsampler>();
    _costmap_downsampler->on_configure(
      node, _global_frame, topic_name, _costmap, _downsampling_factor);
  }

  _raw_plan_publisher = node->create_publisher<nav_msgs::msg::Path>("unsmoothed_plan", 1);

  RCLCPP_INFO(
    _logger, "Configured plugin %s of type MySmacPlanner2D with "
    "tolerance %.2f, maximum iterations %i, "
    "max on approach iterations %i, and %s.",
    _name.c_str(), _tolerance, _max_iterations, _max_on_approach_iterations,
    _allow_unknown ? "allowing unknown traversal" : "not allowing unknown traversal");
}

void MySmacPlanner2D::activate()
{
  RCLCPP_INFO(
    _logger, "Activating plugin %s of type MySmacPlanner2D",
    _name.c_str());
  _raw_plan_publisher->on_activate();
  if (_costmap_downsampler) {
    _costmap_downsampler->on_activate();
  }
  auto node = _node.lock();
  // Add callback for dynamic parameters
  _dyn_params_handler = node->add_on_set_parameters_callback(
    std::bind(&MySmacPlanner2D::dynamicParametersCallback, this, _1));
}

void MySmacPlanner2D::deactivate()
{
  RCLCPP_INFO(
    _logger, "Deactivating plugin %s of type MySmacPlanner2D",
    _name.c_str());
  _raw_plan_publisher->on_deactivate();
  if (_costmap_downsampler) {
    _costmap_downsampler->on_deactivate();
  }
  _dyn_params_handler.reset();
}

void MySmacPlanner2D::cleanup()
{
  RCLCPP_INFO(
    _logger, "Cleaning up plugin %s of type MySmacPlanner2D",
    _name.c_str());
  _a_star.reset();
  _smoother.reset();
  if (_costmap_downsampler) {
    _costmap_downsampler->on_cleanup();
    _costmap_downsampler.reset();
  }
  _raw_plan_publisher.reset();
}

nav_msgs::msg::Path MySmacPlanner2D::createPlan(
  const geometry_msgs::msg::PoseStamped & start,
  const geometry_msgs::msg::PoseStamped & goal,
  const std::vector<my_intermediate_interfaces::msg::VertexConstraint> vertex_constraints,
  const std::vector<my_intermediate_interfaces::msg::EdgeConstraint> edge_constraints)
{
  std::lock_guard<std::mutex> lock_reinit(_mutex);
  steady_clock::time_point a = steady_clock::now();

  std::unique_lock<nav2_costmap_2d::Costmap2D::mutex_t> lock(*(_costmap->getMutex()));

  // Downsample costmap, if required
  nav2_costmap_2d::Costmap2D * costmap = _costmap;
  if (_costmap_downsampler) {
    costmap = _costmap_downsampler->downsample(_downsampling_factor);
    _collision_checker.setCostmap(costmap);
  }

  // Set collision checker and costmap information
  _a_star->setCollisionChecker(&_collision_checker);

  // Set starting point
  unsigned int mx_start, my_start, mx_goal, my_goal;
  costmap->worldToMap(start.pose.position.x, start.pose.position.y, mx_start, my_start);
  _a_star->setStart(mx_start, my_start, 0);

  // Set goal point
  costmap->worldToMap(goal.pose.position.x, goal.pose.position.y, mx_goal, my_goal);
  _a_star->setGoal(mx_goal, my_goal, 0);

  // Setup message
  nav_msgs::msg::Path plan;
  plan.header.stamp = _clock->now();
  plan.header.frame_id = _global_frame;
  geometry_msgs::msg::PoseStamped pose;
  pose.header = plan.header;
  pose.pose.position.z = 0.0;
  pose.pose.orientation.x = 0.0;
  pose.pose.orientation.y = 0.0;
  pose.pose.orientation.z = 0.0;
  pose.pose.orientation.w = 1.0;
  //RCLCPP_WARN(_logger, "SMAC PLANNER");
  // Corner case of start and goal beeing on the same cell
  if (mx_start == mx_goal && my_start == my_goal) {
    if (costmap->getCost(mx_start, my_start) == nav2_costmap_2d::LETHAL_OBSTACLE) {
      RCLCPP_WARN(_logger, "Failed to create a unique pose path because of obstacles");
      return plan;
    }
    pose.pose = start.pose;
    // if we have a different start and goal orientation, set the unique path pose to the goal
    // orientation, unless use_final_approach_orientation=true where we need it to be the start
    // orientation to avoid movement from the local planner
    if (start.pose.orientation != goal.pose.orientation && !_use_final_approach_orientation) {
      pose.pose.orientation = goal.pose.orientation;
    }
    plan.poses.push_back(pose);
    return plan;
  }

  std::vector<std::map<std::string, int>> vert_constr;
  std::vector<std::map<std::string, int>> edge_constr;

  for (const auto& obj : vertex_constraints) {
      double constr_x = obj.cell.x;
      double constr_y = obj.cell.y;
      unsigned int cx, cy;
      costmap->worldToMap(constr_x, constr_y, cx, cy);
      //int idx = cy * planner_->nx + cx;
      int idx = cy * _a_star->getSizeX() + cx;
      std::map<std::string, int> object = {{"cell", idx}, {"time_step", obj.time_step}};
      vert_constr.push_back(object);
  }

  for (const auto& obj : edge_constraints) {
      double constr_1_x = obj.cell_from.x;
      double constr_1_y = obj.cell_from.y;
      double constr_2_x = obj.cell_to.x;
      double constr_2_y = obj.cell_to.y;
      unsigned int cx1, cx2, cy1, cy2;
      costmap->worldToMap(constr_1_x, constr_1_y, cx1, cy1);
      costmap->worldToMap(constr_2_x, constr_2_y, cx2, cy2);
      int idx1 = cy1 * _a_star->getSizeX() + cx1;
      int idx2 = cy2 * _a_star->getSizeX() + cx2;
      std::map<std::string, int> object = {{"cell_from", idx1}, {"cell_to", idx2}, {"time_step", obj.time_step}};
      edge_constr.push_back(object);
  }

  // Compute plan
  Node2D::CoordinateVector path;
  int num_iterations = 0;
  std::string error;
  try {
    if (!_a_star->createPath(
        path, num_iterations, _tolerance / static_cast<float>(costmap->getResolution()), vert_constr, edge_constr))
    {
      if (num_iterations < _a_star->getMaxIterations()) {
        error = std::string("no valid path found");
      } else {
        error = std::string("exceeded maximum iterations");
      }
    }
  } catch (const std::runtime_error & e) {
    error = "invalid use: ";
    error += e.what();
  }

  if (!error.empty()) {
    RCLCPP_WARN(
      _logger,
      "%s: failed to create plan, %s.",
      _name.c_str(), error.c_str());
    return plan;
  }

  // Convert to world coordinates
  plan.poses.reserve(path.size());
  for (int i = path.size() - 1; i >= 0; --i) {
    pose.pose = getWorldCoords(path[i].x, path[i].y, costmap);
    plan.poses.push_back(pose);
  }

  // Publish raw path for debug
  if (_raw_plan_publisher->get_subscription_count() > 0) {
    _raw_plan_publisher->publish(plan);
  }

  // Find how much time we have left to do smoothing
  steady_clock::time_point b = steady_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(b - a);
  double time_remaining = _max_planning_time - static_cast<double>(time_span.count());

#ifdef BENCHMARK_TESTING
  std::cout << "It took " << time_span.count() * 1000 <<
    " milliseconds with " << num_iterations << " iterations." << std::endl;
#endif

  // Smooth plan
  _smoother->smooth(plan, costmap, time_remaining);

  // If use_final_approach_orientation=true, interpolate the last pose orientation from the
  // previous pose to set the orientation to the 'final approach' orientation of the robot so
  // it does not rotate.
  // And deal with corner case of plan of length 1
  // If use_final_approach_orientation=false (default), override last pose orientation to match goal
  size_t plan_size = plan.poses.size();
  if (_use_final_approach_orientation) {
    if (plan_size == 1) {
      plan.poses.back().pose.orientation = start.pose.orientation;
    } else if (plan_size > 1) {
      double dx, dy, theta;
      auto last_pose = plan.poses.back().pose.position;
      auto approach_pose = plan.poses[plan_size - 2].pose.position;
      dx = last_pose.x - approach_pose.x;
      dy = last_pose.y - approach_pose.y;
      theta = atan2(dy, dx);
      plan.poses.back().pose.orientation =
        nav2_util::geometry_utils::orientationAroundZAxis(theta);
    }
  } else if (plan_size > 0) {
    plan.poses.back().pose.orientation = goal.pose.orientation;
  }

  return plan;
}

rcl_interfaces::msg::SetParametersResult
MySmacPlanner2D::dynamicParametersCallback(std::vector<rclcpp::Parameter> parameters)
{
  rcl_interfaces::msg::SetParametersResult result;
  std::lock_guard<std::mutex> lock_reinit(_mutex);

  bool reinit_a_star = false;
  bool reinit_downsampler = false;

  for (auto parameter : parameters) {
    const auto & type = parameter.get_type();
    const auto & name = parameter.get_name();

    if (type == ParameterType::PARAMETER_DOUBLE) {
      if (name == _name + ".tolerance") {
        _tolerance = static_cast<float>(parameter.as_double());
      } else if (name == _name + ".cost_travel_multiplier") {
        reinit_a_star = true;
        _search_info.cost_penalty = parameter.as_double();
      } else if (name == _name + ".max_planning_time") {
        reinit_a_star = true;
        _max_planning_time = parameter.as_double();
      }
    } else if (type == ParameterType::PARAMETER_BOOL) {
      if (name == _name + ".downsample_costmap") {
        reinit_downsampler = true;
        _downsample_costmap = parameter.as_bool();
      } else if (name == _name + ".allow_unknown") {
        reinit_a_star = true;
        _allow_unknown = parameter.as_bool();
      } else if (name == _name + ".use_final_approach_orientation") {
        _use_final_approach_orientation = parameter.as_bool();
      }
    } else if (type == ParameterType::PARAMETER_INTEGER) {
      if (name == _name + ".downsampling_factor") {
        reinit_downsampler = true;
        _downsampling_factor = parameter.as_int();
      } else if (name == _name + ".max_iterations") {
        reinit_a_star = true;
        _max_iterations = parameter.as_int();
        if (_max_iterations <= 0) {
          RCLCPP_INFO(
            _logger, "maximum iteration selected as <= 0, "
            "disabling maximum iterations.");
          _max_iterations = std::numeric_limits<int>::max();
        }
      } else if (name == _name + ".max_on_approach_iterations") {
        reinit_a_star = true;
        _max_on_approach_iterations = parameter.as_int();
        if (_max_on_approach_iterations <= 0) {
          RCLCPP_INFO(
            _logger, "On approach iteration selected as <= 0, "
            "disabling tolerance and on approach iterations.");
          _max_on_approach_iterations = std::numeric_limits<int>::max();
        }
      }
    }
  }

  // Re-init if needed with mutex lock (to avoid re-init while creating a plan)
  if (reinit_a_star || reinit_downsampler) {
    // Re-Initialize A* template
    if (reinit_a_star) {
      _a_star = std::make_unique<AStarAlgorithm<Node2D>>(_motion_model, _search_info);
      _a_star->initialize(
        _allow_unknown,
        _max_iterations,
        _max_on_approach_iterations,
        _max_planning_time,
        0.0 /*unused for 2D*/,
        1.0 /*unused for 2D*/);
    }

    // Re-Initialize costmap downsampler
    if (reinit_downsampler) {
      if (_downsample_costmap && _downsampling_factor > 1) {
        auto node = _node.lock();
        std::string topic_name = "downsampled_costmap";
        _costmap_downsampler = std::make_unique<CostmapDownsampler>();
        _costmap_downsampler->on_configure(
          node, _global_frame, topic_name, _costmap, _downsampling_factor);
      }
    }
  }
  result.successful = true;
  return result;
}

}  // namespace my_nav2_smac_planner

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(my_nav2_smac_planner::MySmacPlanner2D, my_nav2_core::MultiAgentGlobalPlanner)
