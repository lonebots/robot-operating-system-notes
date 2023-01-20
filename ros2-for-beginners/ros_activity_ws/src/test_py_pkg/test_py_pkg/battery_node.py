#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from functools import partial

from custom_interfaces.srv import SetLed


class BatteryNode (Node):
    def __init__(self) -> None:
        super().__init__("battery_node")
        self.battery_status_update_client = self.create_client(
            SetLed, 'set_led')

        self.battery_empty_timer_ = self.create_timer(
            4, self.call_set_battery_empty)
        self.battery_full_timer_ = self.create_timer(
            6, self.call_set_battery_full)

        self.get_logger().info("battery node started")

    def call_set_battery_full(self):
        request = SetLed.Request()
        request.led_number = 3
        request.state = 'on'
        future = self.battery_status_update_client.call_async(request)

        future.add_done_callback(partial(self.callback_set_battery))

    def call_set_battery_empty(self):
        request = SetLed.Request()
        request.led_number = 3
        request.state = 'off'
        future = self.battery_status_update_client.call_async(request)

        future.add_done_callback(partial(self.callback_set_battery))

    def callback_set_battery(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"{response}")
        except Exception as e:
            self.get_logger().info(
                f"service call failure with exception : {e}")


def main(args=None):
    rclpy.init(args=args)
    node = BatteryNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
