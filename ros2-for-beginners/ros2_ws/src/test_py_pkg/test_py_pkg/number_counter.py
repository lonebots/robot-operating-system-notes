#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64


class NumberCounterNode(Node):
    def __init__(self) -> None:
        super().__init__("number_counter")
        self.counter_ = 0
        self.counter_publisher_ = self.create_publisher(
            Int64, "number_count", 10)
        self.number_subscriber_ = self.create_subscription(
            Int64, "number", self.subcription_callback, 10)

        self.get_logger().info("Number Counter Node started")

    def subcription_callback(self, msg):
        self.get_logger().info(f"subscribed to number topic : {msg.data}")

        # update counter
        self.counter_ += msg.data

        # call the publisher to number count topic
        new_msg = Int64()
        new_msg.data = self.counter_
        self.counter_publisher_.publish(new_msg)


def main(args=None):
    rclpy.init()
    node = NumberCounterNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
