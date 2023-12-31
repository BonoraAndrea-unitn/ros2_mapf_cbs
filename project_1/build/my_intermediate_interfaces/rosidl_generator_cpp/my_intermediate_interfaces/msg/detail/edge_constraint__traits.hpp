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

namespace my_intermediate_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const EdgeConstraint & msg,
  std::ostream & out)
{
  out << "{";
  // member: cell_from_index
  {
    out << "cell_from_index: ";
    rosidl_generator_traits::value_to_yaml(msg.cell_from_index, out);
    out << ", ";
  }

  // member: cell_to_index
  {
    out << "cell_to_index: ";
    rosidl_generator_traits::value_to_yaml(msg.cell_to_index, out);
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
  // member: cell_from_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cell_from_index: ";
    rosidl_generator_traits::value_to_yaml(msg.cell_from_index, out);
    out << "\n";
  }

  // member: cell_to_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cell_to_index: ";
    rosidl_generator_traits::value_to_yaml(msg.cell_to_index, out);
    out << "\n";
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
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_intermediate_interfaces::msg::EdgeConstraint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_intermediate_interfaces::msg::EdgeConstraint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__EDGE_CONSTRAINT__TRAITS_HPP_
