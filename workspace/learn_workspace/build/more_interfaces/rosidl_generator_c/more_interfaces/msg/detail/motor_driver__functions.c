// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from more_interfaces:msg/MotorDriver.idl
// generated code does not contain a copyright notice
#include "more_interfaces/msg/detail/motor_driver__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `device_id`
#include "rosidl_runtime_c/string_functions.h"

bool
more_interfaces__msg__MotorDriver__init(more_interfaces__msg__MotorDriver * msg)
{
  if (!msg) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__init(&msg->device_id)) {
    more_interfaces__msg__MotorDriver__fini(msg);
    return false;
  }
  // rot_ang
  // power_in
  // rpm
  return true;
}

void
more_interfaces__msg__MotorDriver__fini(more_interfaces__msg__MotorDriver * msg)
{
  if (!msg) {
    return;
  }
  // device_id
  rosidl_runtime_c__String__fini(&msg->device_id);
  // rot_ang
  // power_in
  // rpm
}

bool
more_interfaces__msg__MotorDriver__are_equal(const more_interfaces__msg__MotorDriver * lhs, const more_interfaces__msg__MotorDriver * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_id), &(rhs->device_id)))
  {
    return false;
  }
  // rot_ang
  if (lhs->rot_ang != rhs->rot_ang) {
    return false;
  }
  // power_in
  if (lhs->power_in != rhs->power_in) {
    return false;
  }
  // rpm
  if (lhs->rpm != rhs->rpm) {
    return false;
  }
  return true;
}

bool
more_interfaces__msg__MotorDriver__copy(
  const more_interfaces__msg__MotorDriver * input,
  more_interfaces__msg__MotorDriver * output)
{
  if (!input || !output) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__copy(
      &(input->device_id), &(output->device_id)))
  {
    return false;
  }
  // rot_ang
  output->rot_ang = input->rot_ang;
  // power_in
  output->power_in = input->power_in;
  // rpm
  output->rpm = input->rpm;
  return true;
}

more_interfaces__msg__MotorDriver *
more_interfaces__msg__MotorDriver__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__msg__MotorDriver * msg = (more_interfaces__msg__MotorDriver *)allocator.allocate(sizeof(more_interfaces__msg__MotorDriver), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(more_interfaces__msg__MotorDriver));
  bool success = more_interfaces__msg__MotorDriver__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
more_interfaces__msg__MotorDriver__destroy(more_interfaces__msg__MotorDriver * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    more_interfaces__msg__MotorDriver__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
more_interfaces__msg__MotorDriver__Sequence__init(more_interfaces__msg__MotorDriver__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__msg__MotorDriver * data = NULL;

  if (size) {
    data = (more_interfaces__msg__MotorDriver *)allocator.zero_allocate(size, sizeof(more_interfaces__msg__MotorDriver), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = more_interfaces__msg__MotorDriver__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        more_interfaces__msg__MotorDriver__fini(&data[i - 1]);
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
more_interfaces__msg__MotorDriver__Sequence__fini(more_interfaces__msg__MotorDriver__Sequence * array)
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
      more_interfaces__msg__MotorDriver__fini(&array->data[i]);
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

more_interfaces__msg__MotorDriver__Sequence *
more_interfaces__msg__MotorDriver__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__msg__MotorDriver__Sequence * array = (more_interfaces__msg__MotorDriver__Sequence *)allocator.allocate(sizeof(more_interfaces__msg__MotorDriver__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = more_interfaces__msg__MotorDriver__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
more_interfaces__msg__MotorDriver__Sequence__destroy(more_interfaces__msg__MotorDriver__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    more_interfaces__msg__MotorDriver__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
more_interfaces__msg__MotorDriver__Sequence__are_equal(const more_interfaces__msg__MotorDriver__Sequence * lhs, const more_interfaces__msg__MotorDriver__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!more_interfaces__msg__MotorDriver__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
more_interfaces__msg__MotorDriver__Sequence__copy(
  const more_interfaces__msg__MotorDriver__Sequence * input,
  more_interfaces__msg__MotorDriver__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(more_interfaces__msg__MotorDriver);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    more_interfaces__msg__MotorDriver * data =
      (more_interfaces__msg__MotorDriver *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!more_interfaces__msg__MotorDriver__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          more_interfaces__msg__MotorDriver__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!more_interfaces__msg__MotorDriver__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
