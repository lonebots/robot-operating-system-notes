# Launch File in ROS

In real world scenarios we may need to start muliple nodes with varrying node_names, parameters etc according to the required architecture in a scalable pattern. Thus we use a single script file that contains information about all the nodes and their specific configurations to start.

`One such file that contains all the configurations of the nodes and their parameters, that helps in starting them with a single launch command is known as a Launch file`

## Setup Launch package

1. create a new package and name following the naming convention <robot_name>`_bringup` with no build type or dependencies specified.
2. Delete the `src/` and `include/` folders and add an new folder named `launch`.
3. Add the following lines in the `CmakeList.txt` file and change the basic file details

```cmake
install(DIRECTORY
  launch
DESTINATION share/${PROJECT_NAME}
)
```

The above command installse every files in the `launch` directory and helps in running multiple packages with a single launch file.

4. create a launch file( python file) inside the `launch` folder and make it executable. example is given below;

**launch_test_app.launch.py**

```python3
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    # python_oop_node
    python_oops_node = Node(
        package="my_py_pkg",
        executable="my_oops_node",
        name="my_python_oops_node"
    )

    # robot_news station
    robot_news_station = Node(
        package="my_cpp_pkg",
        executable="robot_news_station",
        name="yoyo_news_robot",
        remappings=[
            ('robot_news', 'yoyo_robot_news_topic')  # for topic and services

        ],
        parameters=[
            #  {key: value } for parameters
        ]
    )

    ld.add_action(python_oops_node)
    ld.add_action(robot_news_station)

    return ld


```

**Note**: The functions name `generate_launch_description` is defaulted to this and error may occur if we tried to change it. This is because during the launching of the node the system looks for the information about the node to be launched in this particular function and thus it throws error if the funciton is not present in the launch file.

5. Compile the package with `colcon build` and it is ready to be executed
