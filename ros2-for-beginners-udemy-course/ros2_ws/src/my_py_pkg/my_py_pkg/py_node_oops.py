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
