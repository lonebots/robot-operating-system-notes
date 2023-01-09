#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

# create a class inheriting from the 'Node' object


class MyNode(Node):

    # initialise and call the super class with name of the node
    def __init__(self):
        super().__init__("py_oops_node")
        self.get_logger().info("hello from python oops node!")

        # implement a timer that counts
        self.counter_ = 0
        # calls timer_callback every 1 sec
        self.create_timer(1, self.timer_callback)

    # timer callback function
    def timer_callback(self):
        self.counter_ += 1  # increment by 1 every second
        self.get_logger().info("oops node counter value : " + str(self.counter_))


def main(args=None):
    rclpy.init()
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
