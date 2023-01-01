cmake_minimum_required(VERSION 3.8)
project(more_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED) # rosidl_default_generators
ament_export_dependencies(rosidl_default_runtime) # amend_export_dependencies

find_package(rclcpp REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

set(msg_files
  #"msg/AddressBook.msg"
  "msg/MotorDriver.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)

# # adding executables pointing to the new program file
# add_executable(publish_address_book src/publish_address_book.cpp)

# # amending target dependencies
# ament_target_dependencies(publish_address_book rclcpp)

# # set target
# install(TARGETS publish_address_book
# DESTINATION lib/${PROJECT_NAME})

# # link against the interface
# rosidl_get_typesupport_target(cpp_typesupport_target
#   ${PROJECT_NAME} "rosidl_typesupport_cpp")

# target_link_libraries(publish_address_book "${cpp_typesupport_target}")



# add executable,ament_target_dependencies,set target,link interface
add_executable(publish_motor_driver src/publish_motor_driver.cpp)
ament_target_dependencies(publish_motor_driver rclcpp)
install(TARGETS publish_motor_driver
DESTINATION   lib/${PROJECT_NAME})
rosidl_get_typesupport_target(cpp_typesupport_target
 ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(publish_motor_driver "${cpp_typesupport_target}")


ament_package()