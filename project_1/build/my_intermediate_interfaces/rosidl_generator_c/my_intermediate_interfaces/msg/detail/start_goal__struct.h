// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_intermediate_interfaces:msg/StartGoal.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__START_GOAL__STRUCT_H_
#define MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__START_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start'
// Member 'goal'
#include "my_intermediate_interfaces/msg/detail/coordinates3_d__struct.h"

/// Struct defined in msg/StartGoal in the package my_intermediate_interfaces.
typedef struct my_intermediate_interfaces__msg__StartGoal
{
  my_intermediate_interfaces__msg__Coordinates3D start;
  my_intermediate_interfaces__msg__Coordinates3D goal;
} my_intermediate_interfaces__msg__StartGoal;

// Struct for a sequence of my_intermediate_interfaces__msg__StartGoal.
typedef struct my_intermediate_interfaces__msg__StartGoal__Sequence
{
  my_intermediate_interfaces__msg__StartGoal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_intermediate_interfaces__msg__StartGoal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__START_GOAL__STRUCT_H_
