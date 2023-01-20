cmake_minimum_required(VERSION 3.8)
project(custom_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()



# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# for msg
set(msg 
"msg/LedStates.msg"
)

# for srv
set(srv
"srv/SetLed.srv"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg}
  ${srv}
)

ament_package()
