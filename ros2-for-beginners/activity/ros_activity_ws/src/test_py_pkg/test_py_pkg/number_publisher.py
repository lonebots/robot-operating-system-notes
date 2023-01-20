#!/usr/bin/python3

import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64


class NumberPubliserNode(Node):
    def __init__(self) -> None:
        super().__init__("number_publisher")

        self.number_ = 10
        self.number_publisher_ = self.create_publisher(Int64, "number", 10)
        self.timer_ = self.create_timer(1, self.publishNumber)

    def publishNumber(self):
        msg = Int64()
        msg.data = self.number_
        self.number_publisher_.publish(msg)


def main(args=None):
    rclpy.init()
    node = NumberPubliserNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
