// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from more_interfaces:msg/MotorDriver.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__FUNCTIONS_H_
#define MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "more_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "more_interfaces/msg/detail/motor_driver__struct.h"

/// Initialize msg/MotorDriver message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * more_interfaces__msg__MotorDriver
 * )) before or use
 * more_interfaces__msg__MotorDriver__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
bool
more_interfaces__msg__MotorDriver__init(more_interfaces__msg__MotorDriver * msg);

/// Finalize msg/MotorDriver message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
void
more_interfaces__msg__MotorDriver__fini(more_interfaces__msg__MotorDriver * msg);

/// Create msg/MotorDriver message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * more_interfaces__msg__MotorDriver__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
more_interfaces__msg__MotorDriver *
more_interfaces__msg__MotorDriver__create();

/// Destroy msg/MotorDriver message.
/**
 * It calls
 * more_interfaces__msg__MotorDriver__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
void
more_interfaces__msg__MotorDriver__destroy(more_interfaces__msg__MotorDriver * msg);

/// Check for msg/MotorDriver message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
bool
more_interfaces__msg__MotorDriver__are_equal(const more_interfaces__msg__MotorDriver * lhs, const more_interfaces__msg__MotorDriver * rhs);

/// Copy a msg/MotorDriver message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
bool
more_interfaces__msg__MotorDriver__copy(
  const more_interfaces__msg__MotorDriver * input,
  more_interfaces__msg__MotorDriver * output);

/// Initialize array of msg/MotorDriver messages.
/**
 * It allocates the memory for the number of elements and calls
 * more_interfaces__msg__MotorDriver__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
bool
more_interfaces__msg__MotorDriver__Sequence__init(more_interfaces__msg__MotorDriver__Sequence * array, size_t size);

/// Finalize array of msg/MotorDriver messages.
/**
 * It calls
 * more_interfaces__msg__MotorDriver__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
void
more_interfaces__msg__MotorDriver__Sequence__fini(more_interfaces__msg__MotorDriver__Sequence * array);

/// Create array of msg/MotorDriver messages.
/**
 * It allocates the memory for the array and calls
 * more_interfaces__msg__MotorDriver__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
more_interfaces__msg__MotorDriver__Sequence *
more_interfaces__msg__MotorDriver__Sequence__create(size_t size);

/// Destroy array of msg/MotorDriver messages.
/**
 * It calls
 * more_interfaces__msg__MotorDriver__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
void
more_interfaces__msg__MotorDriver__Sequence__destroy(more_interfaces__msg__MotorDriver__Sequence * array);

/// Check for msg/MotorDriver message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
bool
more_interfaces__msg__MotorDriver__Sequence__are_equal(const more_interfaces__msg__MotorDriver__Sequence * lhs, const more_interfaces__msg__MotorDriver__Sequence * rhs);

/// Copy an array of msg/MotorDriver messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
bool
more_interfaces__msg__MotorDriver__Sequence__copy(
  const more_interfaces__msg__MotorDriver__Sequence * input,
  more_interfaces__msg__MotorDriver__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__FUNCTIONS_H_
