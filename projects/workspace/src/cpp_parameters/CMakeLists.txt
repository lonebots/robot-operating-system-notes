cmake_minimum_required(VERSION 3.8)
project(cpp_parameters)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# setup parameter node
add_executable(parameter_node "src/cpp_parameters_node.cpp")
ament_target_dependencies(parameter_node "rclcpp")
install(TARGETS 
parameter_node
DESTINATION lib/${PROJECT_NAME}
)

ament_package()
