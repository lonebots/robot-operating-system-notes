#!/usr/bin/python3

import rclpy
from rclpy.node import Node


class BatteryNode (Node):
    def __init__(self) -> None:
        super().__init__("battery_node")


def main(args=None):
    rclpy.init(args=args)
    node = BatteryNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
