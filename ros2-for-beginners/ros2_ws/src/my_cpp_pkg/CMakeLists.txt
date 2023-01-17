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

# publisher subscriber : start
add_executable(robot_news_station src/robot_news_station.cpp)
ament_target_dependencies(robot_news_station rclcpp example_interfaces)

add_executable(smartphone src/smartphone.cpp)
ament_target_dependencies(smartphone rclcpp example_interfaces)

install(TARGETS 
  robot_news_station
  smartphone
  DESTINATION lib/${PROJECT_NAME}
  )

# publisher subscriber : end

# install the executable
# similar to the setup.cfg in the python package
install(TARGETS 
  cpp_node
  DESTINATION lib/${PROJECT_NAME}
)


add_executable(cpp_oops_node src/cpp_oops_node.cpp)
ament_target_dependencies(cpp_oops_node rclcpp)
install(TARGETS
cpp_oops_node
DESTINATION lib/${PROJECT_NAME})

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
