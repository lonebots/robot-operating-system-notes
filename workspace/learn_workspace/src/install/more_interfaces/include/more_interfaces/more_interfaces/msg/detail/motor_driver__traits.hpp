// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from more_interfaces:msg/MotorDriver.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__TRAITS_HPP_
#define MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "more_interfaces/msg/detail/motor_driver__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace more_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorDriver & msg,
  std::ostream & out)
{
  out << "{";
  // member: device_id
  {
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << ", ";
  }

  // member: rot_ang
  {
    out << "rot_ang: ";
    rosidl_generator_traits::value_to_yaml(msg.rot_ang, out);
    out << ", ";
  }

  // member: power_in
  {
    out << "power_in: ";
    rosidl_generator_traits::value_to_yaml(msg.power_in, out);
    out << ", ";
  }

  // member: rpm
  {
    out << "rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.rpm, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorDriver & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: device_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << "\n";
  }

  // member: rot_ang
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rot_ang: ";
    rosidl_generator_traits::value_to_yaml(msg.rot_ang, out);
    out << "\n";
  }

  // member: power_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_in: ";
    rosidl_generator_traits::value_to_yaml(msg.power_in, out);
    out << "\n";
  }

  // member: rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.rpm, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorDriver & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace more_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use more_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const more_interfaces::msg::MotorDriver & msg,
  std::ostream & out, size_t indentation = 0)
{
  more_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use more_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const more_interfaces::msg::MotorDriver & msg)
{
  return more_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<more_interfaces::msg::MotorDriver>()
{
  return "more_interfaces::msg::MotorDriver";
}

template<>
inline const char * name<more_interfaces::msg::MotorDriver>()
{
  return "more_interfaces/msg/MotorDriver";
}

template<>
struct has_fixed_size<more_interfaces::msg::MotorDriver>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<more_interfaces::msg::MotorDriver>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<more_interfaces::msg::MotorDriver>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__TRAITS_HPP_
