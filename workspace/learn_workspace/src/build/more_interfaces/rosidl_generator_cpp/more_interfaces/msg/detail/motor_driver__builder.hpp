// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from more_interfaces:msg/MotorDriver.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__BUILDER_HPP_
#define MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "more_interfaces/msg/detail/motor_driver__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace more_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorDriver_rpm
{
public:
  explicit Init_MotorDriver_rpm(::more_interfaces::msg::MotorDriver & msg)
  : msg_(msg)
  {}
  ::more_interfaces::msg::MotorDriver rpm(::more_interfaces::msg::MotorDriver::_rpm_type arg)
  {
    msg_.rpm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::msg::MotorDriver msg_;
};

class Init_MotorDriver_power_in
{
public:
  explicit Init_MotorDriver_power_in(::more_interfaces::msg::MotorDriver & msg)
  : msg_(msg)
  {}
  Init_MotorDriver_rpm power_in(::more_interfaces::msg::MotorDriver::_power_in_type arg)
  {
    msg_.power_in = std::move(arg);
    return Init_MotorDriver_rpm(msg_);
  }

private:
  ::more_interfaces::msg::MotorDriver msg_;
};

class Init_MotorDriver_rot_ang
{
public:
  explicit Init_MotorDriver_rot_ang(::more_interfaces::msg::MotorDriver & msg)
  : msg_(msg)
  {}
  Init_MotorDriver_power_in rot_ang(::more_interfaces::msg::MotorDriver::_rot_ang_type arg)
  {
    msg_.rot_ang = std::move(arg);
    return Init_MotorDriver_power_in(msg_);
  }

private:
  ::more_interfaces::msg::MotorDriver msg_;
};

class Init_MotorDriver_device_id
{
public:
  Init_MotorDriver_device_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorDriver_rot_ang device_id(::more_interfaces::msg::MotorDriver::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return Init_MotorDriver_rot_ang(msg_);
  }

private:
  ::more_interfaces::msg::MotorDriver msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::msg::MotorDriver>()
{
  return more_interfaces::msg::builder::Init_MotorDriver_device_id();
}

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__BUILDER_HPP_
