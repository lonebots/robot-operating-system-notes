#!/usr/bin/python3

import rclpy
from rclpy.node import Node


class AddTwoIntClient(Node):
    def __init__(self) -> None:
        super().__init__('add_two_ints_client')

        self.get_logger().info("python add two int client started")


def main(args=None):
    rclpy.init()
    node = AddTwoIntClient()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
