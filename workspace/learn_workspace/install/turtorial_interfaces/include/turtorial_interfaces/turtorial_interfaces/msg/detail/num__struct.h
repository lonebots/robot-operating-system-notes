// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtorial_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TURTORIAL_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_
#define TURTORIAL_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Num in the package turtorial_interfaces.
typedef struct turtorial_interfaces__msg__Num
{
  int64_t num;
} turtorial_interfaces__msg__Num;

// Struct for a sequence of turtorial_interfaces__msg__Num.
typedef struct turtorial_interfaces__msg__Num__Sequence
{
  turtorial_interfaces__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtorial_interfaces__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTORIAL_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_
