#!/usr/bin/python3
import rclpy
from rclpy.node import Node

# import the messge type from example interfaces
from example_interfaces.msg import String


class RobotNewsStationNode(Node):
    def __init__(self) -> None:
        super().__init__("robot_news_station")

        '''
        create a publisher object
        using create_publisher method of Node class 
        takes in 3 arguements 
            1. message type.
            2. topic to which it publishes.
            3. queue size -- to keep some message before discarding the previous ones, acts as buffer,
                it allows the application to keep some messages before they are processed.
        '''
        self.publisher_ = self.create_publisher(String, "robot_news", 10)

        # create a timer to publish the message in regular intervals
        self.timer_ = self.create_timer(0.5, self.publish_news)

        # log
        self.get_logger().info("Robot News Station has been started.")

    # create a function to publish the news
    def publish_news(self):
        msg = String()
        msg.data = 'Hello'
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init()
    node = RobotNewsStationNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
