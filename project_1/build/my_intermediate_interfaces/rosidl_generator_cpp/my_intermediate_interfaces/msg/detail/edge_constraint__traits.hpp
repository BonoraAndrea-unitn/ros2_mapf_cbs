// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_intermediate_interfaces:msg/EdgeConstraint.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__EDGE_CONSTRAINT__TRAITS_HPP_
#define MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__EDGE_CONSTRAINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_intermediate_interfaces/msg/detail/edge_constraint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'starting_cell'
// Member 'goal_cell'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace my_intermediate_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const EdgeConstraint & msg,
  std::ostream & out)
{
  out << "{";
  // member: agent_name
  {
    out << "agent_name: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_name, out);
    out << ", ";
  }

  // member: starting_cell
  {
    out << "starting_cell: ";
    to_flow_style_yaml(msg.starting_cell, out);
    out << ", ";
  }

  // member: goal_cell
  {
    out << "goal_cell: ";
    to_flow_style_yaml(msg.goal_cell, out);
    out << ", ";
  }

  // member: time_step
  {
    out << "time_step: ";
    rosidl_generator_traits::value_to_yaml(msg.time_step, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EdgeConstraint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: agent_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agent_name: ";
    rosidl_generator_traits::value_to_yaml(msg.agent_name, out);
    out << "\n";
  }

  // member: starting_cell
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "starting_cell:\n";
    to_block_style_yaml(msg.starting_cell, out, indentation + 2);
  }

  // member: goal_cell
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_cell:\n";
    to_block_style_yaml(msg.goal_cell, out, indentation + 2);
  }

  // member: time_step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_step: ";
    rosidl_generator_traits::value_to_yaml(msg.time_step, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EdgeConstraint & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_intermediate_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_intermediate_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_intermediate_interfaces::msg::EdgeConstraint & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_intermediate_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_intermediate_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_intermediate_interfaces::msg::EdgeConstraint & msg)
{
  return my_intermediate_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_intermediate_interfaces::msg::EdgeConstraint>()
{
  return "my_intermediate_interfaces::msg::EdgeConstraint";
}

template<>
inline const char * name<my_intermediate_interfaces::msg::EdgeConstraint>()
{
  return "my_intermediate_interfaces/msg/EdgeConstraint";
}

template<>
struct has_fixed_size<my_intermediate_interfaces::msg::EdgeConstraint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_intermediate_interfaces::msg::EdgeConstraint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_intermediate_interfaces::msg::EdgeConstraint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__EDGE_CONSTRAINT__TRAITS_HPP_