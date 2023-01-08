# ROS2 for Beginner Course - Udemy

[course link](https://www.udemy.com/course/ros2-for-beginners/)

This section contains my learning of ROS2 with the above course in udemy learning platform. This course covers all the basics of ros2 using python and c++ as basic programming languages. This course is highly recommended for pure beginner the prerequisities for the course are

- Ubuntu installation[dual boot or virtual machine] ( > 20.04)
- ROS installation (ros2)
- Basic knowledge of python or C++

### ROS introduction

[**ROS**](https://ros.org/)(Robotic operating system) is a middleware software that can be installed on Linux or Windows based machine and used to program robots. The software enables user to code a robot from scratch very easily. It reduces the intial environment setup overhead and makes the process more simpler. Here basically each of the different components in a robot are considered as **nodes**, multiple nodes are created and they communicate each other to achieve the dezired action by the robot.

You can follow the official [ros.org](https://ros.org/) page for [installation](https://www.ros.org/blog/getting-started/) guide and I would recommend you to install the latest or LTS version that is currently available.(at the time of writing this, I would recommend ros2 [Humble Hawksbill](https://docs.ros.org/en/humble/Installation.html) which is an LTS version and supported ob [Ubuntu 222.04](https://ubuntu.com/download))

You can follow the [tutorials](https://docs.ros.org/en/humble/Tutorials.html) in the official documentation for trying out basic stuffs with ros2. Some of the things which I felt important while I have learned it are mentioned below;

### Basic terminologies to keep in mind :

- [x] [Node](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Nodes/Understanding-ROS2-Nodes.html) : Node is a basic unit(element) in ros that is responsible for controlling an individual part of the robot( say for eg: wheels, motors, hand joints etc.). Nodes communicate via Topic, Service or actions
- [x] [Topic](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Topics/Understanding-ROS2-Topics.html) : Topic acts as a bus for node to exchange messages. There are publisher and susbcriber nodes, they publish to the topics and get subscribed to the topic for communication. when a node subscribe to a topic all the messages in the topic will be available to it.

- [x] [Service](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Services/Understanding-ROS2-Services.html) : IT s request-response based communication model. Here there can be multiple clients but, only one service server for a particular service.

- [x] [Parameter](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Parameters/Understanding-ROS2-Parameters.html) : These are addional configuration value (integers, floats, booleans, strings, and lists are supported) that we pass in to a node while its processing. It can be set from a sensor or can be feed manually.

- [x] [Actions](https://docs.ros.org/en/humble/Tutorials/Beginner-CLI-Tools/Understanding-ROS2-Actions/Understanding-ROS2-Actions.html) : Mode of communication intended for lengthy task. it contains 3 parts: goal, feedback, result.
- [x] [Colcon](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html) - build tool, that is used for building the packages and making it executable in ros2 environment, in ros1 we used **catkin** as the build tool. **ament is the build system here**

### ROS workspace

In ROS, first thing we need is a [workspace](), it is just a simple folder you can name it as your wish(we will create a folder called `ros2_ws`). But make sure that sure to create an `src` inside `ros2_ws`. It is in here furture coding (making packages) are done

```bash
mkdir -p ros2_ws/src
cd ros2_ws/src
```

### ROS Package

Packages are simply organised container of ros2 code. It make it easy to install dependencies and share our code. Packages can be created in python as well as C++ and they contains their own formats ans boiler plate code. Let' create a package using the below command

**All the packages must lie in the `src` folder of the workspace**

```bash
# for python package
ros2 pkg create --build-type ament_python my_py_pkg

# for cpp package
ros2 pkg create --build-type ament_cmake my_cpp_pkg

```

You need a node for building the package and execute something. for that you can try out on in [this](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html)

### Building a Package

For building a package we can use `colcon build`, it is build tool as we have already mentioned above. The command is used along with `--packages-select` option to provide the package name we wish to build.

```bash
# colcon build --packages-select <package name>

colcon build --packages-select my_py_pkg

```

The above is just and example and you may not have anything to be build on the python package since it will only contain some boiler plate code.

This gives the basic setup of ROS2 and I will be continuing my notes inside the notes folder for each chapter or topic

**[continued in `notes` folder]**
