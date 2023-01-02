// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtorial_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TURTORIAL_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
#define TURTORIAL_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtorial_interfaces/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtorial_interfaces::msg::Num num(::turtorial_interfaces::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtorial_interfaces::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtorial_interfaces::msg::Num>()
{
  return turtorial_interfaces::msg::builder::Init_Num_num();
}

}  // namespace turtorial_interfaces

#endif  // TURTORIAL_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
