#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import int


class NumberCounterNode(Node):
    def __init__(self) -> None:
        super().__init__("number_counter")
        self.counter_ = 0
        self.subscriber_ = self.create_subscription(
            int, "number", self.callbackCounter, 10)
        self.publisher_ = self.create_publisher(int, "number_count", 10)

        self.timer_ = self.create_timer(1, publishCount)

    def callbackCounter(self, msg):
        self.get_logger().info(f"subscribed to number topic : {msg.data}")

        # call the publisher to number count topic
        self.publishCount(int(msg.data))

    def publishCount(self, number):
        count += number
        self.publisher_.publish(count)


def main(args=None):
    rclpy.init()
    node = NumberCounterNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
