#!/usr/bin/python3

import rclpy
from rclpy.node import Node


class MyCustomNode(Node):
    def __init__(self) -> None:
        super().__init__("my_custom_node")


def main(args=None):
    rclpy.init(args=args)
    node = MyCustomNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
