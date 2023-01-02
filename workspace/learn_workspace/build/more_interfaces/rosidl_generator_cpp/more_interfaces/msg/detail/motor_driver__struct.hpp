// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from more_interfaces:msg/MotorDriver.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__STRUCT_HPP_
#define MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__more_interfaces__msg__MotorDriver __attribute__((deprecated))
#else
# define DEPRECATED__more_interfaces__msg__MotorDriver __declspec(deprecated)
#endif

namespace more_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorDriver_
{
  using Type = MotorDriver_<ContainerAllocator>;

  explicit MotorDriver_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_id = "";
      this->rot_ang = 0;
      this->power_in = 0;
      this->rpm = 0ull;
    }
  }

  explicit MotorDriver_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : device_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_id = "";
      this->rot_ang = 0;
      this->power_in = 0;
      this->rpm = 0ull;
    }
  }

  // field types and members
  using _device_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_id_type device_id;
  using _rot_ang_type =
    uint8_t;
  _rot_ang_type rot_ang;
  using _power_in_type =
    uint8_t;
  _power_in_type power_in;
  using _rpm_type =
    uint64_t;
  _rpm_type rpm;

  // setters for named parameter idiom
  Type & set__device_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_id = _arg;
    return *this;
  }
  Type & set__rot_ang(
    const uint8_t & _arg)
  {
    this->rot_ang = _arg;
    return *this;
  }
  Type & set__power_in(
    const uint8_t & _arg)
  {
    this->power_in = _arg;
    return *this;
  }
  Type & set__rpm(
    const uint64_t & _arg)
  {
    this->rpm = _arg;
    return *this;
  }

  // constant declarations
  static constexpr bool ON =
    1;
  static constexpr bool OFF =
    0;

  // pointer types
  using RawPtr =
    more_interfaces::msg::MotorDriver_<ContainerAllocator> *;
  using ConstRawPtr =
    const more_interfaces::msg::MotorDriver_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<more_interfaces::msg::MotorDriver_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<more_interfaces::msg::MotorDriver_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      more_interfaces::msg::MotorDriver_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::msg::MotorDriver_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      more_interfaces::msg::MotorDriver_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::msg::MotorDriver_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<more_interfaces::msg::MotorDriver_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<more_interfaces::msg::MotorDriver_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__more_interfaces__msg__MotorDriver
    std::shared_ptr<more_interfaces::msg::MotorDriver_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__more_interfaces__msg__MotorDriver
    std::shared_ptr<more_interfaces::msg::MotorDriver_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorDriver_ & other) const
  {
    if (this->device_id != other.device_id) {
      return false;
    }
    if (this->rot_ang != other.rot_ang) {
      return false;
    }
    if (this->power_in != other.power_in) {
      return false;
    }
    if (this->rpm != other.rpm) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorDriver_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorDriver_

// alias to use template instance with default allocator
using MotorDriver =
  more_interfaces::msg::MotorDriver_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr bool MotorDriver_<ContainerAllocator>::ON;
template<typename ContainerAllocator>
constexpr bool MotorDriver_<ContainerAllocator>::OFF;

}  // namespace msg

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__MSG__DETAIL__MOTOR_DRIVER__STRUCT_HPP_
