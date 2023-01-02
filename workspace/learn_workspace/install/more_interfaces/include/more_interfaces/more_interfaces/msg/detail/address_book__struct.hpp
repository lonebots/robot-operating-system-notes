// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from more_interfaces:msg/AddressBook.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__STRUCT_HPP_
#define MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__more_interfaces__msg__AddressBook __attribute__((deprecated))
#else
# define DEPRECATED__more_interfaces__msg__AddressBook __declspec(deprecated)
#endif

namespace more_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AddressBook_
{
  using Type = AddressBook_<ContainerAllocator>;

  explicit AddressBook_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->first_name = "";
      this->last_name = "";
      this->gender = false;
      this->age = 0;
      this->address = "";
    }
  }

  explicit AddressBook_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : first_name(_alloc),
    last_name(_alloc),
    address(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->first_name = "";
      this->last_name = "";
      this->gender = false;
      this->age = 0;
      this->address = "";
    }
  }

  // field types and members
  using _first_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _first_name_type first_name;
  using _last_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _last_name_type last_name;
  using _gender_type =
    bool;
  _gender_type gender;
  using _age_type =
    uint8_t;
  _age_type age;
  using _address_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _address_type address;

  // setters for named parameter idiom
  Type & set__first_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->first_name = _arg;
    return *this;
  }
  Type & set__last_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->last_name = _arg;
    return *this;
  }
  Type & set__gender(
    const bool & _arg)
  {
    this->gender = _arg;
    return *this;
  }
  Type & set__age(
    const uint8_t & _arg)
  {
    this->age = _arg;
    return *this;
  }
  Type & set__address(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->address = _arg;
    return *this;
  }

  // constant declarations
  static constexpr bool FEMALE =
    1;
  static constexpr bool MALE =
    0;

  // pointer types
  using RawPtr =
    more_interfaces::msg::AddressBook_<ContainerAllocator> *;
  using ConstRawPtr =
    const more_interfaces::msg::AddressBook_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<more_interfaces::msg::AddressBook_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<more_interfaces::msg::AddressBook_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      more_interfaces::msg::AddressBook_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::msg::AddressBook_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      more_interfaces::msg::AddressBook_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<more_interfaces::msg::AddressBook_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<more_interfaces::msg::AddressBook_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<more_interfaces::msg::AddressBook_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__more_interfaces__msg__AddressBook
    std::shared_ptr<more_interfaces::msg::AddressBook_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__more_interfaces__msg__AddressBook
    std::shared_ptr<more_interfaces::msg::AddressBook_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AddressBook_ & other) const
  {
    if (this->first_name != other.first_name) {
      return false;
    }
    if (this->last_name != other.last_name) {
      return false;
    }
    if (this->gender != other.gender) {
      return false;
    }
    if (this->age != other.age) {
      return false;
    }
    if (this->address != other.address) {
      return false;
    }
    return true;
  }
  bool operator!=(const AddressBook_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AddressBook_

// alias to use template instance with default allocator
using AddressBook =
  more_interfaces::msg::AddressBook_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr bool AddressBook_<ContainerAllocator>::FEMALE;
template<typename ContainerAllocator>
constexpr bool AddressBook_<ContainerAllocator>::MALE;

}  // namespace msg

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__STRUCT_HPP_
