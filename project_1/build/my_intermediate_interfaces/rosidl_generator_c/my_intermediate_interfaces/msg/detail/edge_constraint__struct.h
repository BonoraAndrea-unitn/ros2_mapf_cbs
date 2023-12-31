// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_intermediate_interfaces:msg/EdgeConstraint.idl
// generated code does not contain a copyright notice

#ifndef MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__EDGE_CONSTRAINT__STRUCT_H_
#define MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__EDGE_CONSTRAINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EdgeConstraint in the package my_intermediate_interfaces.
typedef struct my_intermediate_interfaces__msg__EdgeConstraint
{
  int64_t cell_from_index;
  int64_t cell_to_index;
  int64_t time_step;
} my_intermediate_interfaces__msg__EdgeConstraint;

// Struct for a sequence of my_intermediate_interfaces__msg__EdgeConstraint.
typedef struct my_intermediate_interfaces__msg__EdgeConstraint__Sequence
{
  my_intermediate_interfaces__msg__EdgeConstraint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_intermediate_interfaces__msg__EdgeConstraint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_INTERMEDIATE_INTERFACES__MSG__DETAIL__EDGE_CONSTRAINT__STRUCT_H_
