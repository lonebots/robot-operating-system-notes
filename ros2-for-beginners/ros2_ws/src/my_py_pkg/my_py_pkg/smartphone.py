#!usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import String


class SmartPhoneNode(Node):
    def __init__(self) -> None:
        super().__init__('smartphone')

        '''
        create a subscription object 
        using create_subscription method of Node class
        takes in 4 arguements
            1. message type 
            2. name of the topic to which the node want to subscribe 
            3. callback function --> every time a message is published to a topic this callback function is invoked
                it will contain the received message('msg') as parameter
            4. message queue size 
        '''
        self.subscriber_ = self.create_subscription(
            String, "robot_news", self.callback_robot_news, 10)

        # log
        self.get_logger().info('smartphone node started')

    # create a callback function for handling what to do with the message
    def callback_robot_news(self, msg):
        self.get_logger().info(f"recieved message : {msg.data}")


def main():
    rclpy.init()
    node = SmartPhoneNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
