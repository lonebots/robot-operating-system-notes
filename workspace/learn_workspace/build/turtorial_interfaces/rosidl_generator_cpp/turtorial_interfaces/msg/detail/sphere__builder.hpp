// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtorial_interfaces:msg/Sphere.idl
// generated code does not contain a copyright notice

#ifndef TURTORIAL_INTERFACES__MSG__DETAIL__SPHERE__BUILDER_HPP_
#define TURTORIAL_INTERFACES__MSG__DETAIL__SPHERE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtorial_interfaces/msg/detail/sphere__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_Sphere_radius
{
public:
  explicit Init_Sphere_radius(::turtorial_interfaces::msg::Sphere & msg)
  : msg_(msg)
  {}
  ::turtorial_interfaces::msg::Sphere radius(::turtorial_interfaces::msg::Sphere::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtorial_interfaces::msg::Sphere msg_;
};

class Init_Sphere_center
{
public:
  Init_Sphere_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sphere_radius center(::turtorial_interfaces::msg::Sphere::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Sphere_radius(msg_);
  }

private:
  ::turtorial_interfaces::msg::Sphere msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtorial_interfaces::msg::Sphere>()
{
  return turtorial_interfaces::msg::builder::Init_Sphere_center();
}

}  // namespace turtorial_interfaces

#endif  // TURTORIAL_INTERFACES__MSG__DETAIL__SPHERE__BUILDER_HPP_
