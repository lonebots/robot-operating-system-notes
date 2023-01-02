// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from more_interfaces:msg/AddressBook.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__STRUCT_H_
#define MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'FEMALE'.
static const bool more_interfaces__msg__AddressBook__FEMALE = true;

/// Constant 'MALE'.
static const bool more_interfaces__msg__AddressBook__MALE = false;

// Include directives for member types
// Member 'first_name'
// Member 'last_name'
// Member 'address'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AddressBook in the package more_interfaces.
typedef struct more_interfaces__msg__AddressBook
{
  rosidl_runtime_c__String first_name;
  rosidl_runtime_c__String last_name;
  bool gender;
  uint8_t age;
  rosidl_runtime_c__String address;
} more_interfaces__msg__AddressBook;

// Struct for a sequence of more_interfaces__msg__AddressBook.
typedef struct more_interfaces__msg__AddressBook__Sequence
{
  more_interfaces__msg__AddressBook * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} more_interfaces__msg__AddressBook__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__STRUCT_H_
