cmake_minimum_required(VERSION 3.8)
project(robot_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# for msg
set(msg
"msg/HardwareStatus.msg"
)

# for srv
set(srv
"srv/ComputeRectangleArea.srv"
)

# generate the interface source code
rosidl_generate_interfaces(${PROJECT_NAME}
${msg}
${srv}
)

ament_package()
