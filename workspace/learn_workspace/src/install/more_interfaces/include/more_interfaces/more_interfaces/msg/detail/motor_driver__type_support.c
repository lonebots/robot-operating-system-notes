// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from more_interfaces:msg/MotorDriver.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "more_interfaces/msg/detail/motor_driver__rosidl_typesupport_introspection_c.h"
#include "more_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "more_interfaces/msg/detail/motor_driver__functions.h"
#include "more_interfaces/msg/detail/motor_driver__struct.h"


// Include directives for member types
// Member `device_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  more_interfaces__msg__MotorDriver__init(message_memory);
}

void more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_fini_function(void * message_memory)
{
  more_interfaces__msg__MotorDriver__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_message_member_array[4] = {
  {
    "device_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__msg__MotorDriver, device_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rot_ang",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__msg__MotorDriver, rot_ang),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "power_in",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__msg__MotorDriver, power_in),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rpm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(more_interfaces__msg__MotorDriver, rpm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_message_members = {
  "more_interfaces__msg",  // message namespace
  "MotorDriver",  // message name
  4,  // number of fields
  sizeof(more_interfaces__msg__MotorDriver),
  more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_message_member_array,  // message members
  more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_init_function,  // function to initialize message memory (memory has to be allocated)
  more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_message_type_support_handle = {
  0,
  &more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_more_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, more_interfaces, msg, MotorDriver)() {
  if (!more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_message_type_support_handle.typesupport_identifier) {
    more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &more_interfaces__msg__MotorDriver__rosidl_typesupport_introspection_c__MotorDriver_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
