#!/usr/bin/python3
import rclpy
from rclpy.node import Node


class RobotNewsStationNode(Node):
    def __init__(self) -> None:
        super().__init__("robot_news_station")


def main(args=None):
    rclpy.init()
    node = RobotNewsStationNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
