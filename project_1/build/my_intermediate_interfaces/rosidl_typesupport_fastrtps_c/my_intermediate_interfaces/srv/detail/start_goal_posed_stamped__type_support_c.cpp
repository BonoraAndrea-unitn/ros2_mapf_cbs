// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_intermediate_interfaces:srv/StartGoalPosedStamped.idl
// generated code does not contain a copyright notice
#include "my_intermediate_interfaces/srv/detail/start_goal_posed_stamped__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_intermediate_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_intermediate_interfaces/srv/detail/start_goal_posed_stamped__struct.h"
#include "my_intermediate_interfaces/srv/detail/start_goal_posed_stamped__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "nav_msgs/msg/detail/path__functions.h"  // plans

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_my_intermediate_interfaces
size_t get_serialized_size_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_my_intermediate_interfaces
size_t max_serialized_size_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_my_intermediate_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path)();


using _StartGoalPosedStamped_Request__ros_msg_type = my_intermediate_interfaces__srv__StartGoalPosedStamped_Request;

static bool _StartGoalPosedStamped_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalPosedStamped_Request__ros_msg_type * ros_message = static_cast<const _StartGoalPosedStamped_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: plans
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path
      )()->data);
    size_t size = ros_message->plans.size;
    auto array_ptr = ros_message->plans.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _StartGoalPosedStamped_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalPosedStamped_Request__ros_msg_type * ros_message = static_cast<_StartGoalPosedStamped_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: plans
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->plans.data) {
      nav_msgs__msg__Path__Sequence__fini(&ros_message->plans);
    }
    if (!nav_msgs__msg__Path__Sequence__init(&ros_message->plans, size)) {
      fprintf(stderr, "failed to create array for field 'plans'");
      return false;
    }
    auto array_ptr = ros_message->plans.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_intermediate_interfaces
size_t get_serialized_size_my_intermediate_interfaces__srv__StartGoalPosedStamped_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalPosedStamped_Request__ros_msg_type * ros_message = static_cast<const _StartGoalPosedStamped_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name plans
  {
    size_t array_size = ros_message->plans.size;
    auto array_ptr = ros_message->plans.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_nav_msgs__msg__Path(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalPosedStamped_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_intermediate_interfaces__srv__StartGoalPosedStamped_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_intermediate_interfaces
size_t max_serialized_size_my_intermediate_interfaces__srv__StartGoalPosedStamped_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: plans
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _StartGoalPosedStamped_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_intermediate_interfaces__srv__StartGoalPosedStamped_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalPosedStamped_Request = {
  "my_intermediate_interfaces::srv",
  "StartGoalPosedStamped_Request",
  _StartGoalPosedStamped_Request__cdr_serialize,
  _StartGoalPosedStamped_Request__cdr_deserialize,
  _StartGoalPosedStamped_Request__get_serialized_size,
  _StartGoalPosedStamped_Request__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalPosedStamped_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalPosedStamped_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_intermediate_interfaces, srv, StartGoalPosedStamped_Request)() {
  return &_StartGoalPosedStamped_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "my_intermediate_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "my_intermediate_interfaces/srv/detail/start_goal_posed_stamped__struct.h"
// already included above
// #include "my_intermediate_interfaces/srv/detail/start_goal_posed_stamped__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "nav_msgs/msg/detail/path__functions.h"  // collision_free_plans

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_my_intermediate_interfaces
size_t get_serialized_size_nav_msgs__msg__Path(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_my_intermediate_interfaces
size_t max_serialized_size_nav_msgs__msg__Path(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_my_intermediate_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path)();


using _StartGoalPosedStamped_Response__ros_msg_type = my_intermediate_interfaces__srv__StartGoalPosedStamped_Response;

static bool _StartGoalPosedStamped_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StartGoalPosedStamped_Response__ros_msg_type * ros_message = static_cast<const _StartGoalPosedStamped_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: collision_free_plans
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path
      )()->data);
    size_t size = ros_message->collision_free_plans.size;
    auto array_ptr = ros_message->collision_free_plans.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _StartGoalPosedStamped_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StartGoalPosedStamped_Response__ros_msg_type * ros_message = static_cast<_StartGoalPosedStamped_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: collision_free_plans
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, nav_msgs, msg, Path
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->collision_free_plans.data) {
      nav_msgs__msg__Path__Sequence__fini(&ros_message->collision_free_plans);
    }
    if (!nav_msgs__msg__Path__Sequence__init(&ros_message->collision_free_plans, size)) {
      fprintf(stderr, "failed to create array for field 'collision_free_plans'");
      return false;
    }
    auto array_ptr = ros_message->collision_free_plans.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_intermediate_interfaces
size_t get_serialized_size_my_intermediate_interfaces__srv__StartGoalPosedStamped_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StartGoalPosedStamped_Response__ros_msg_type * ros_message = static_cast<const _StartGoalPosedStamped_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name collision_free_plans
  {
    size_t array_size = ros_message->collision_free_plans.size;
    auto array_ptr = ros_message->collision_free_plans.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_nav_msgs__msg__Path(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StartGoalPosedStamped_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_intermediate_interfaces__srv__StartGoalPosedStamped_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_intermediate_interfaces
size_t max_serialized_size_my_intermediate_interfaces__srv__StartGoalPosedStamped_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: collision_free_plans
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_nav_msgs__msg__Path(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _StartGoalPosedStamped_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_intermediate_interfaces__srv__StartGoalPosedStamped_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StartGoalPosedStamped_Response = {
  "my_intermediate_interfaces::srv",
  "StartGoalPosedStamped_Response",
  _StartGoalPosedStamped_Response__cdr_serialize,
  _StartGoalPosedStamped_Response__cdr_deserialize,
  _StartGoalPosedStamped_Response__get_serialized_size,
  _StartGoalPosedStamped_Response__max_serialized_size
};

static rosidl_message_type_support_t _StartGoalPosedStamped_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StartGoalPosedStamped_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_intermediate_interfaces, srv, StartGoalPosedStamped_Response)() {
  return &_StartGoalPosedStamped_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "my_intermediate_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_intermediate_interfaces/srv/start_goal_posed_stamped.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t StartGoalPosedStamped__callbacks = {
  "my_intermediate_interfaces::srv",
  "StartGoalPosedStamped",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_intermediate_interfaces, srv, StartGoalPosedStamped_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_intermediate_interfaces, srv, StartGoalPosedStamped_Response)(),
};

static rosidl_service_type_support_t StartGoalPosedStamped__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &StartGoalPosedStamped__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_intermediate_interfaces, srv, StartGoalPosedStamped)() {
  return &StartGoalPosedStamped__handle;
}

#if defined(__cplusplus)
}
#endif
