cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# custom_change : start

# add the file in executable section
add_executable(cpp_node src/my_first_node.cpp)
ament_target_dependecies(cpp_node rclcpp)  # this linking is specific to the ament library --> not related to cmake commands
# above line 15, 16 create an executable

# install the executable
# similar to the setup.cfg in the python package
install(TARGETS 
  cpp_node 
  DESTINATION lib/${PROJECT_NAME}
)

# custom_change : end

ament_package()
