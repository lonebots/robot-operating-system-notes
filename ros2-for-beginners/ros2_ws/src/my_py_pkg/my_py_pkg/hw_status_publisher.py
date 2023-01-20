#!/usr/bin/python3

import rclpy
from rclpy.node import Node

# custom interface
from robot_interfaces.msg import HardwareStatus


class HardwareStatusPublisherNode(Node):
    def __init__(self) -> None:
        super().__init__("hardware_status_publisher")
        self.hw_status_publisher_ = self.create_publisher(
            HardwareStatus, 'hardware_status', 10)
        self.timer_ = self.create_timer(1, self.publishHardwareStatus)
        self.get_logger().info('hardware status publisher node started')

    def publishHardwareStatus(self):
        msg = HardwareStatus()
        msg.temperature = 78
        msg.are_motors_ready = False
        msg.debug_message = 'motors not ready to engage'
        self.hw_status_publisher_.publish(msg)
        self.get_logger().info(f"\nhardware status : {msg}")


def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
