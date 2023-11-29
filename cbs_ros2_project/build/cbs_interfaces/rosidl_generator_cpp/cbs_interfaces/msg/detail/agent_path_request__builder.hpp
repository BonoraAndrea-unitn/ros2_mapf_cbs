// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cbs_interfaces:msg/AgentPathRequest.idl
// generated code does not contain a copyright notice

#ifndef CBS_INTERFACES__MSG__DETAIL__AGENT_PATH_REQUEST__BUILDER_HPP_
#define CBS_INTERFACES__MSG__DETAIL__AGENT_PATH_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cbs_interfaces/msg/detail/agent_path_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cbs_interfaces
{

namespace msg
{

namespace builder
{

class Init_AgentPathRequest_edge_constraints
{
public:
  explicit Init_AgentPathRequest_edge_constraints(::cbs_interfaces::msg::AgentPathRequest & msg)
  : msg_(msg)
  {}
  ::cbs_interfaces::msg::AgentPathRequest edge_constraints(::cbs_interfaces::msg::AgentPathRequest::_edge_constraints_type arg)
  {
    msg_.edge_constraints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cbs_interfaces::msg::AgentPathRequest msg_;
};

class Init_AgentPathRequest_vertex_constraints
{
public:
  explicit Init_AgentPathRequest_vertex_constraints(::cbs_interfaces::msg::AgentPathRequest & msg)
  : msg_(msg)
  {}
  Init_AgentPathRequest_edge_constraints vertex_constraints(::cbs_interfaces::msg::AgentPathRequest::_vertex_constraints_type arg)
  {
    msg_.vertex_constraints = std::move(arg);
    return Init_AgentPathRequest_edge_constraints(msg_);
  }

private:
  ::cbs_interfaces::msg::AgentPathRequest msg_;
};

class Init_AgentPathRequest_goal
{
public:
  explicit Init_AgentPathRequest_goal(::cbs_interfaces::msg::AgentPathRequest & msg)
  : msg_(msg)
  {}
  Init_AgentPathRequest_vertex_constraints goal(::cbs_interfaces::msg::AgentPathRequest::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return Init_AgentPathRequest_vertex_constraints(msg_);
  }

private:
  ::cbs_interfaces::msg::AgentPathRequest msg_;
};

class Init_AgentPathRequest_start
{
public:
  explicit Init_AgentPathRequest_start(::cbs_interfaces::msg::AgentPathRequest & msg)
  : msg_(msg)
  {}
  Init_AgentPathRequest_goal start(::cbs_interfaces::msg::AgentPathRequest::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_AgentPathRequest_goal(msg_);
  }

private:
  ::cbs_interfaces::msg::AgentPathRequest msg_;
};

class Init_AgentPathRequest_name
{
public:
  Init_AgentPathRequest_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AgentPathRequest_start name(::cbs_interfaces::msg::AgentPathRequest::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_AgentPathRequest_start(msg_);
  }

private:
  ::cbs_interfaces::msg::AgentPathRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cbs_interfaces::msg::AgentPathRequest>()
{
  return cbs_interfaces::msg::builder::Init_AgentPathRequest_name();
}

}  // namespace cbs_interfaces

#endif  // CBS_INTERFACES__MSG__DETAIL__AGENT_PATH_REQUEST__BUILDER_HPP_
