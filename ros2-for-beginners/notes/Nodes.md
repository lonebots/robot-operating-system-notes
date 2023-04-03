# Node

Node is the basic unit of a ros program. It handles everthing related to a particular part of a robot for eg, a gear-mortor, servo, sensor, camera etc.

Nodes make it easy to handle things related to single entity or object.

Take an example of a camera pkg it may contain the following node

- camera driver node : for capturing the image
- image processing node : to do the basic image processing job
- some more extra programs

For motion planning package we may have

- motion planning node
- path correction node : continuously interact with the motion planning node.

For the Hardware control we may have

- state publisher
- Main control loop
- drivers : for handling the motors, controlled by the main control loop

Each node can be launched separately and they communicate each other via topics, sevices or actions.

### Characteristics of Node

- reduce the code complexity
- Node provide good debugging capablities(fault tolerance)
- support for multiple programming languges

### Creating your first Node

## Python Node :

reference for [rclpy Node](https://docs.ros2.org/latest/api/rclpy/api/node.html)

creating a node in python package, navigate to the `ros2_ws/src/my_py_pkg/my_py_pkg` and create a file `my_first_node.py`

**my_first_node.py**

```bash
cd ros2_ws/src/my_py_pkg/my_py_pkg
touch my_first_node.py
```

you may copy paste the below program or the code can be found in the respecitve folder of this repository.

```python
# import the library for ros2 functionality
import rclpy

def main(args=None):
    rclpy.init(args=args)  # initialise the rclpy communication

    # create a node
    node = rclpy.create_node("py_test")

    # hello world in ros2
    node.get_logger().info("Hello ROS2")

    # very important -- allow node to be alive continuously
    rclpy.spin(node)

    rclpy.shutdown()  # last line of every program

    pass


if __name__ == "__main__":
    main()

```

After creating the node make the file executable using `chmod +x my_first_node.py` and run the program using

```bash
python3 my_first_node.py
```

you may get the output as

> [INFO] [1673203700.060777181] [py_test]: Hello ROS2

### How to setup this in executable file ?

This is to inform ros2 how to make the file executable and specify the entry point to the program. update the `entry_point` in the `setup.py` file like give below:

```python
entry_points={
        'console_scripts': [
            "py_node = my_py_pkg.my_first_node:main"
        ],
    }
```

here, `py_node` is the name of the new node executable that is going to be installed in `ros2_ws/src/install/my_py_pkg/lib/my_py_pkg/py_node` location.

### How to run the Node in the package ?

follow the below steps:

1. source the current ros2 environment by running following command from the `src` directory
   ```bash
   source ./install/setup.bash
   source ./install/local_setup.bash
   ```
2. run the package using

   ```bash
    ros2 run my_py_pkg py_node
   ```

**Note :** we call the node with the entry point name (`py_node`) provide in the `setup.py` file.

## Python Node With OOPS

implementing the node as a class using the python **OOPS** concept make it more scalable and easy to managel. You may change the code as given below in the previous file `my_first_node.py` or create a new file `my_node_oops.py` and repeat the general steps followed earlier. The code for the file is given below and the procedure for making it executable is as followed earlier.

```python
#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

# create a class inheriting from the 'Node' object
class MyNode(Node) :

    # initialise and call the super class with name of the node
    def __init__(self) :
        super().__init__("py_oops_node")
        self.get_logger().info("hello from python oops node!")


def main(args=None):
    rclpy.init()
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()


```

### Implementing Counter with callback Timer!

For creating a general timer, using the api `create_timer` and setting the time limit and specifying a `call_back` function. The above **Node** class, that we have created can be edited as given below to implement the counter.

```python
class MyNode(Node):

    # initialise and call the super class with name of the node
    def __init__(self):
        super().__init__("py_oops_node")
        self.get_logger().info("hello from python oops node!")

        # implement a timer that counts
        self.counter_ = 0
        # calls timer_callback every 1 sec
        self.create_timer(1, self.timer_callback)

    # timer callback function
    def timer_callback(self):
        self.counter_ += 1  # increment by 1 every second
        self.get_logger().info("oops node counter value : " + str(self.counter_))

```

you can run the above node similar to the previous one using the `ros2 run` command specifying the `<package_name>` and `<executable_name>`

### Running same node after renaming it!

we use `--ros-args` flag along with `--rmap` or `-r` flag to rename. The command is as given below.

```bash
ros2 run my_py_pkg my_oops_node --ros-args --rmap __node:=my_oops_node1
ros2 run my_py_pkg my_oops_node --ros-args --rmap __node:=my_oops_node2
```

using the remap functionality the same node can be run with different name.

**Note:** What happens when we run the same node with the same name multiple times? This won't show any error during the run time but it can create many **unintentional** error when the application grows or the nodes try to communicate with each other. We can use the `ros2 node list` command to see the warning when we try to run the same node multiple times with the same **node_name** to duplicate some behaviours.
