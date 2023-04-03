# ROS2 Interface

These are the messages and services that we use within a topic or service. (for eg: `example_interfaces` contains a lot of sample interface templates to start with). We can also create our own custom interfaces that suites more for the purpose.

Topics and services are the communication layer tools and interfaces/messages are the actual content that we send.

The package contains a message definition, the build system(ament_cmake or ament_python) will convert it in to source code for any ros2 supported languages ( python , C++ ,etc)

we cannot include a service in another service, we can only include messages inside another service.

---

#### Message Template

- file extension : **.msg**
- content

```

# comment
<data_type> <variable name>

```

#### Template for service

- file extension : **.srv**
- content --> here request and response is separted using a `---` line

```

# comment
request msgs
---
response msgs

```

# Custom Interface Definition


**step 0**

- Generate a package using `ros2 pkg create` without using `--build-type` and specifying any `dependencies`.
- remove the folders : `include/` and `src/`
- create new folders : `msg/` and `srv/`

### Pacakge setup

1. update pacakge.xml - include the following lines :

```xml
<build_depend>rosidl_default_generators</build_depend>
<exec_depend>rosidl_default_runtime</exec_depend>
<member_of_group>rosidl_interface_packages</member_of_group>
```

2. update CmakeLists.txt file - include the following lines :

```cmake
# include find package
find_package(rosidl_interface_generators REQUIRED)


# generate the source code for the interfaces
rosidl_generate_interfaces(

${PROJECT_NAME}
"srv/custom_service.srv"    #"path_to_srv"
"msb/custom_messge.msg"     #"path_to_msg"

)
```

3. build the package using `colcon build`

