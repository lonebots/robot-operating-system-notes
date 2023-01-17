#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import int


class NumberPubliserNode(Node):
    def __init__(self) -> None:
        super().__init__("number_publisher")

        self.publisher_ = self.create_publisher(int, "number", 10)

    def publishNumber(self):
        msg = int()
        msg.data = 123
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init()
    node = NumberPubliserNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
