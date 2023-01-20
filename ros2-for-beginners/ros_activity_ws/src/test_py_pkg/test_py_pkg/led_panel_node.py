#!/usr/bin/python3

import rclpy
from rclpy.node import Node

from custom_interfaces.srv import SetLed
from custom_interfaces.msg import LedStates


class LedPanelNode(Node):
    def __init__(self) -> None:
        super().__init__("led_panel_node")

        # variables
        self.led_state_ = [0, 0, 0]

        """
        create a server 
            1. 

        create a publisher 
        """

        # server
        self.led_state_update_service_ = self.create_service(
            SetLed, "set_led", self.callback_led_state_update_service)

        # publisher
        self.led_state_publisher_ = self.create_publisher(
            LedStates, "led_panel_state", 10)
        self.led_state_publish_timer_ = self.create_timer(
            1, self.publishLedState)

        self.get_logger().info("led panel node started")

    def publishLedState(self):
        msg = LedStates()
        msg.led_states = self.led_state_
        self.led_state_publisher_.publish(msg)

    def callback_led_state_update_service(self, request, response):
        if (request.led_number - 1) < 3:
            if request.state.lower() == "on":
                self.led_state_[request.led_number-1] = 1
                response.success = True
            elif request.state.lower() == "off":
                self.led_state_[request.led_number-1] = 0
                response.success = False
        else:
            self.get_logger().error("Error in processing the request")
            response.success = False

        return response


def main(args=None):
    rclpy.init(args=args)
    node = LedPanelNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
