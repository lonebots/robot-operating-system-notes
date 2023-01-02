// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from more_interfaces:msg/MotorDriver.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__STRUCT_H_
#define MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ON'.
static const bool more_interfaces__msg__MotorDriver__ON = true;

/// Constant 'OFF'.
static const bool more_interfaces__msg__MotorDriver__OFF = false;

// Include directives for member types
// Member 'device_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MotorDriver in the package more_interfaces.
typedef struct more_interfaces__msg__MotorDriver
{
  rosidl_runtime_c__String device_id;
  uint8_t rot_ang;
  uint8_t power_in;
  uint64_t rpm;
} more_interfaces__msg__MotorDriver;

// Struct for a sequence of more_interfaces__msg__MotorDriver.
typedef struct more_interfaces__msg__MotorDriver__Sequence
{
  more_interfaces__msg__MotorDriver * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} more_interfaces__msg__MotorDriver__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__STRUCT_H_
