// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cbs_interfaces:srv/StartGoalPoseStamped.idl
// generated code does not contain a copyright notice
#include "cbs_interfaces/srv/detail/start_goal_pose_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `requests`
#include "cbs_interfaces/msg/detail/agent_path_request__functions.h"

bool
cbs_interfaces__srv__StartGoalPoseStamped_Request__init(cbs_interfaces__srv__StartGoalPoseStamped_Request * msg)
{
  if (!msg) {
    return false;
  }
  // requests
  if (!cbs_interfaces__msg__AgentPathRequest__Sequence__init(&msg->requests, 0)) {
    cbs_interfaces__srv__StartGoalPoseStamped_Request__fini(msg);
    return false;
  }
  return true;
}

void
cbs_interfaces__srv__StartGoalPoseStamped_Request__fini(cbs_interfaces__srv__StartGoalPoseStamped_Request * msg)
{
  if (!msg) {
    return;
  }
  // requests
  cbs_interfaces__msg__AgentPathRequest__Sequence__fini(&msg->requests);
}

bool
cbs_interfaces__srv__StartGoalPoseStamped_Request__are_equal(const cbs_interfaces__srv__StartGoalPoseStamped_Request * lhs, const cbs_interfaces__srv__StartGoalPoseStamped_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // requests
  if (!cbs_interfaces__msg__AgentPathRequest__Sequence__are_equal(
      &(lhs->requests), &(rhs->requests)))
  {
    return false;
  }
  return true;
}

bool
cbs_interfaces__srv__StartGoalPoseStamped_Request__copy(
  const cbs_interfaces__srv__StartGoalPoseStamped_Request * input,
  cbs_interfaces__srv__StartGoalPoseStamped_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // requests
  if (!cbs_interfaces__msg__AgentPathRequest__Sequence__copy(
      &(input->requests), &(output->requests)))
  {
    return false;
  }
  return true;
}

cbs_interfaces__srv__StartGoalPoseStamped_Request *
cbs_interfaces__srv__StartGoalPoseStamped_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cbs_interfaces__srv__StartGoalPoseStamped_Request * msg = (cbs_interfaces__srv__StartGoalPoseStamped_Request *)allocator.allocate(sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Request));
  bool success = cbs_interfaces__srv__StartGoalPoseStamped_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cbs_interfaces__srv__StartGoalPoseStamped_Request__destroy(cbs_interfaces__srv__StartGoalPoseStamped_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cbs_interfaces__srv__StartGoalPoseStamped_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence__init(cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cbs_interfaces__srv__StartGoalPoseStamped_Request * data = NULL;

  if (size) {
    data = (cbs_interfaces__srv__StartGoalPoseStamped_Request *)allocator.zero_allocate(size, sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cbs_interfaces__srv__StartGoalPoseStamped_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cbs_interfaces__srv__StartGoalPoseStamped_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence__fini(cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cbs_interfaces__srv__StartGoalPoseStamped_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence *
cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence * array = (cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence *)allocator.allocate(sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence__destroy(cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence__are_equal(const cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence * lhs, const cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cbs_interfaces__srv__StartGoalPoseStamped_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence__copy(
  const cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence * input,
  cbs_interfaces__srv__StartGoalPoseStamped_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cbs_interfaces__srv__StartGoalPoseStamped_Request * data =
      (cbs_interfaces__srv__StartGoalPoseStamped_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cbs_interfaces__srv__StartGoalPoseStamped_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cbs_interfaces__srv__StartGoalPoseStamped_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cbs_interfaces__srv__StartGoalPoseStamped_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `plans`
#include "cbs_interfaces/msg/detail/agent_path__functions.h"

bool
cbs_interfaces__srv__StartGoalPoseStamped_Response__init(cbs_interfaces__srv__StartGoalPoseStamped_Response * msg)
{
  if (!msg) {
    return false;
  }
  // plans
  if (!cbs_interfaces__msg__AgentPath__Sequence__init(&msg->plans, 0)) {
    cbs_interfaces__srv__StartGoalPoseStamped_Response__fini(msg);
    return false;
  }
  return true;
}

void
cbs_interfaces__srv__StartGoalPoseStamped_Response__fini(cbs_interfaces__srv__StartGoalPoseStamped_Response * msg)
{
  if (!msg) {
    return;
  }
  // plans
  cbs_interfaces__msg__AgentPath__Sequence__fini(&msg->plans);
}

bool
cbs_interfaces__srv__StartGoalPoseStamped_Response__are_equal(const cbs_interfaces__srv__StartGoalPoseStamped_Response * lhs, const cbs_interfaces__srv__StartGoalPoseStamped_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // plans
  if (!cbs_interfaces__msg__AgentPath__Sequence__are_equal(
      &(lhs->plans), &(rhs->plans)))
  {
    return false;
  }
  return true;
}

bool
cbs_interfaces__srv__StartGoalPoseStamped_Response__copy(
  const cbs_interfaces__srv__StartGoalPoseStamped_Response * input,
  cbs_interfaces__srv__StartGoalPoseStamped_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // plans
  if (!cbs_interfaces__msg__AgentPath__Sequence__copy(
      &(input->plans), &(output->plans)))
  {
    return false;
  }
  return true;
}

cbs_interfaces__srv__StartGoalPoseStamped_Response *
cbs_interfaces__srv__StartGoalPoseStamped_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cbs_interfaces__srv__StartGoalPoseStamped_Response * msg = (cbs_interfaces__srv__StartGoalPoseStamped_Response *)allocator.allocate(sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Response));
  bool success = cbs_interfaces__srv__StartGoalPoseStamped_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cbs_interfaces__srv__StartGoalPoseStamped_Response__destroy(cbs_interfaces__srv__StartGoalPoseStamped_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cbs_interfaces__srv__StartGoalPoseStamped_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence__init(cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cbs_interfaces__srv__StartGoalPoseStamped_Response * data = NULL;

  if (size) {
    data = (cbs_interfaces__srv__StartGoalPoseStamped_Response *)allocator.zero_allocate(size, sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cbs_interfaces__srv__StartGoalPoseStamped_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cbs_interfaces__srv__StartGoalPoseStamped_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence__fini(cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cbs_interfaces__srv__StartGoalPoseStamped_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence *
cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence * array = (cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence *)allocator.allocate(sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence__destroy(cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence__are_equal(const cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence * lhs, const cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cbs_interfaces__srv__StartGoalPoseStamped_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence__copy(
  const cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence * input,
  cbs_interfaces__srv__StartGoalPoseStamped_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cbs_interfaces__srv__StartGoalPoseStamped_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cbs_interfaces__srv__StartGoalPoseStamped_Response * data =
      (cbs_interfaces__srv__StartGoalPoseStamped_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cbs_interfaces__srv__StartGoalPoseStamped_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cbs_interfaces__srv__StartGoalPoseStamped_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cbs_interfaces__srv__StartGoalPoseStamped_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
