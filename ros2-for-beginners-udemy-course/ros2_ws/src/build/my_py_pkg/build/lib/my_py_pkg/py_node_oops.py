#!/usr/bin/env python3

import rclpy
from rclpy.node import Node


def main(args=None):
    rclpy.init()
    node = Node("py_oop_node")
    node.get_logger().info("hello from python oops node!")
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
