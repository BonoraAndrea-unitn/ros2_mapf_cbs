// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cbs_interfaces:msg/AgentPath.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cbs_interfaces/msg/detail/agent_path__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cbs_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void AgentPath_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cbs_interfaces::msg::AgentPath(_init);
}

void AgentPath_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cbs_interfaces::msg::AgentPath *>(message_memory);
  typed_message->~AgentPath();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AgentPath_message_member_array[2] = {
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cbs_interfaces::msg::AgentPath, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nav_msgs::msg::Path>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cbs_interfaces::msg::AgentPath, path),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AgentPath_message_members = {
  "cbs_interfaces::msg",  // message namespace
  "AgentPath",  // message name
  2,  // number of fields
  sizeof(cbs_interfaces::msg::AgentPath),
  AgentPath_message_member_array,  // message members
  AgentPath_init_function,  // function to initialize message memory (memory has to be allocated)
  AgentPath_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AgentPath_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AgentPath_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cbs_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cbs_interfaces::msg::AgentPath>()
{
  return &::cbs_interfaces::msg::rosidl_typesupport_introspection_cpp::AgentPath_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cbs_interfaces, msg, AgentPath)() {
  return &::cbs_interfaces::msg::rosidl_typesupport_introspection_cpp::AgentPath_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif