#!/usr/bin/env python3   --> interpreter line for python3

''' 
    steps 
    1. import rclpy library for getting additional ros2 functionality
    2. intialise rclpy for communication (mandatory for every program)
    3. create a node using the Node class
    4. Do something with the node
    5. spin the node --> make it alive continuously
    6. when the program end rclpy.shutdown()

    * install the program via setup.py file

    inital execution
    1. simply make the file executable using 
        chmod +x my_first_node.py
    2. run it as normal python3 program
        python3 my_first_node.py
'''
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
