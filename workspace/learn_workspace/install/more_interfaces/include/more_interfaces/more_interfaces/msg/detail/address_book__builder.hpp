// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from more_interfaces:msg/AddressBook.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__BUILDER_HPP_
#define MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "more_interfaces/msg/detail/address_book__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace more_interfaces
{

namespace msg
{

namespace builder
{

class Init_AddressBook_address
{
public:
  explicit Init_AddressBook_address(::more_interfaces::msg::AddressBook & msg)
  : msg_(msg)
  {}
  ::more_interfaces::msg::AddressBook address(::more_interfaces::msg::AddressBook::_address_type arg)
  {
    msg_.address = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::msg::AddressBook msg_;
};

class Init_AddressBook_age
{
public:
  explicit Init_AddressBook_age(::more_interfaces::msg::AddressBook & msg)
  : msg_(msg)
  {}
  Init_AddressBook_address age(::more_interfaces::msg::AddressBook::_age_type arg)
  {
    msg_.age = std::move(arg);
    return Init_AddressBook_address(msg_);
  }

private:
  ::more_interfaces::msg::AddressBook msg_;
};

class Init_AddressBook_gender
{
public:
  explicit Init_AddressBook_gender(::more_interfaces::msg::AddressBook & msg)
  : msg_(msg)
  {}
  Init_AddressBook_age gender(::more_interfaces::msg::AddressBook::_gender_type arg)
  {
    msg_.gender = std::move(arg);
    return Init_AddressBook_age(msg_);
  }

private:
  ::more_interfaces::msg::AddressBook msg_;
};

class Init_AddressBook_last_name
{
public:
  explicit Init_AddressBook_last_name(::more_interfaces::msg::AddressBook & msg)
  : msg_(msg)
  {}
  Init_AddressBook_gender last_name(::more_interfaces::msg::AddressBook::_last_name_type arg)
  {
    msg_.last_name = std::move(arg);
    return Init_AddressBook_gender(msg_);
  }

private:
  ::more_interfaces::msg::AddressBook msg_;
};

class Init_AddressBook_first_name
{
public:
  Init_AddressBook_first_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddressBook_last_name first_name(::more_interfaces::msg::AddressBook::_first_name_type arg)
  {
    msg_.first_name = std::move(arg);
    return Init_AddressBook_last_name(msg_);
  }

private:
  ::more_interfaces::msg::AddressBook msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::msg::AddressBook>()
{
  return more_interfaces::msg::builder::Init_AddressBook_first_name();
}

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__MSG__DETAIL__ADDRESS_BOOK__BUILDER_HPP_
