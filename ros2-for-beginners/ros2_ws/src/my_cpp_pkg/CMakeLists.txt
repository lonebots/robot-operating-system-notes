cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

# custom_change : start

# add the file in executable section
add_executable(cpp_node src/my_first_node.cpp)
ament_target_dependencies(cpp_node rclcpp)  # this linking is specific to the ament library --> not related to cmake commands
# above line 15, 16 create an executable

add_executable(cpp_oops_node src/cpp_oops_node.cpp) # oop node
ament_target_dependencies(cpp_oops_node rclcpp)

# publisher/subscriber 
add_executable(robot_news_station src/robot_news_station.cpp) # publisher
ament_target_dependencies(robot_news_station rclcpp example_interfaces)

add_executable(smartphone src/smartphone.cpp) # subscriber 
ament_target_dependencies(smartphone rclcpp example_interfaces)

# client/server
add_executable(add_two_ints_server src/add_two_ints_server.cpp) # server
ament_target_dependencies(add_two_ints_server rclcpp example_interfaces)

add_executable(add_two_ints_client_no_oop src/add_two_ints_client_no_oop.cpp) # client no oop
ament_target_dependencies(add_two_ints_client_no_oop rclcpp example_interfaces)

# target installs
install(TARGETS 
  cpp_node
  cpp_oops_node
  robot_news_station
  smartphone
  add_two_ints_server
  add_two_ints_client_no_oop
  DESTINATION lib/${PROJECT_NAME}
  )

# custom_change : end


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
