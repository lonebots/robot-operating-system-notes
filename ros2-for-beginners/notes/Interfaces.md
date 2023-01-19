# ROS2 Interface

These are the messages and services that we use within a topic or service. (for eg: `example_interfaces` contains a lot of sample interface templates to start with). We can also create our own custom interfaces that suites more for the purpose.

Topic and services are the communication layer tools and interfaces/messages are the actual content that we send.

The package contains a message defenition the build system(ament_cmake or ament_python) will convert it in to source code for any ros2 supported languages ( python , C++ ,etc)

we cannot include a service in a service, we can only include messages in servie

---

#### Message Template

- file extension : **.msg**
- content

```

# comment
<data_type> <varible name>

```

#### Template for service

- file extension : **.srv**
- content

```

# comment
request msgs
---
response msgs

```

# Custom Message Definition

