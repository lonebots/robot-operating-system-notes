// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from more_interfaces:msg/MotorDriver.idl
// generated code does not contain a copyright notice
#include "more_interfaces/msg/detail/motor_driver__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "more_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "more_interfaces/msg/detail/motor_driver__struct.h"
#include "more_interfaces/msg/detail/motor_driver__functions.h"
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

#include "rosidl_runtime_c/string.h"  // device_id
#include "rosidl_runtime_c/string_functions.h"  // device_id

// forward declare type support functions


using _MotorDriver__ros_msg_type = more_interfaces__msg__MotorDriver;

static bool _MotorDriver__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MotorDriver__ros_msg_type * ros_message = static_cast<const _MotorDriver__ros_msg_type *>(untyped_ros_message);
  // Field name: device_id
  {
    const rosidl_runtime_c__String * str = &ros_message->device_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: rot_ang
  {
    cdr << ros_message->rot_ang;
  }

  // Field name: power_in
  {
    cdr << ros_message->power_in;
  }

  // Field name: rpm
  {
    cdr << ros_message->rpm;
  }

  return true;
}

static bool _MotorDriver__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MotorDriver__ros_msg_type * ros_message = static_cast<_MotorDriver__ros_msg_type *>(untyped_ros_message);
  // Field name: device_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->device_id.data) {
      rosidl_runtime_c__String__init(&ros_message->device_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->device_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'device_id'\n");
      return false;
    }
  }

  // Field name: rot_ang
  {
    cdr >> ros_message->rot_ang;
  }

  // Field name: power_in
  {
    cdr >> ros_message->power_in;
  }

  // Field name: rpm
  {
    cdr >> ros_message->rpm;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_more_interfaces
size_t get_serialized_size_more_interfaces__msg__MotorDriver(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MotorDriver__ros_msg_type * ros_message = static_cast<const _MotorDriver__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name device_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->device_id.size + 1);
  // field.name rot_ang
  {
    size_t item_size = sizeof(ros_message->rot_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name power_in
  {
    size_t item_size = sizeof(ros_message->power_in);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rpm
  {
    size_t item_size = sizeof(ros_message->rpm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MotorDriver__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_more_interfaces__msg__MotorDriver(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_more_interfaces
size_t max_serialized_size_more_interfaces__msg__MotorDriver(
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

  // member: device_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: rot_ang
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: power_in
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rpm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _MotorDriver__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_more_interfaces__msg__MotorDriver(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MotorDriver = {
  "more_interfaces::msg",
  "MotorDriver",
  _MotorDriver__cdr_serialize,
  _MotorDriver__cdr_deserialize,
  _MotorDriver__get_serialized_size,
  _MotorDriver__max_serialized_size
};

static rosidl_message_type_support_t _MotorDriver__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MotorDriver,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, more_interfaces, msg, MotorDriver)() {
  return &_MotorDriver__type_support;
}

#if defined(__cplusplus)
}
#endif
