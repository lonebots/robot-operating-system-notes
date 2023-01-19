#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64
from example_interfaces.srv import SetBool


class NumberCounterNode(Node):
    def __init__(self) -> None:
        super().__init__("number_counter")
        self.counter_ = 0

        self.counter_publisher_ = self.create_publisher(
            Int64, "number_count", 10)
        self.number_subscriber_ = self.create_subscription(
            Int64, "number", self.subcription_callback, 10)

        self.reset_counter_server_ = self.create_service(
            SetBool, "reset_counter", self.callback_reset_counter
        )

        self.get_logger().info("Number Counter Node started")

    def subcription_callback(self, msg):
        self.get_logger().info(f"subscribed to number topic : {msg.data}")

        # update counter
        self.counter_ += msg.data

        # call the publisher to number count topic
        new_msg = Int64()
        new_msg.data = self.counter_
        self.counter_publisher_.publish(new_msg)

    """
    for a service 
        1. define an instance  - (srv_type,srv_name,callback)
        2. define a callback - (request, response)
    """

    def callback_reset_counter(self, request, response):
        try:
            if (request.data):
                self.counter_ = 0
                response.success = True
                response.message = "successfull reset counter"
                self.get_logger().error(
                    f"reset success --> counter : {self.counter_}")
            else:
                response.success = True
                response.message = "counter value not requested to reset"
                self.get_logger().warn(
                    f"reset not requested --> counter : {self.counter_}")
            return response
        except Exception as e:
            response.success = False
            response.message = "Exception in reset counter"
            self.get_logger().error(
                f"reset failed --> counter : {self.counter_}")
            return response


def main(args=None):
    rclpy.init()
    node = NumberCounterNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
