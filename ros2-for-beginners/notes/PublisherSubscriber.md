# ROS publisher subscriber

These are two basic node types. namely the publisher and the subscriber.

**Publisher** :
The node which is responsible for publishing messages to a topic. The messages are published to respective topics created by the publisher.

**Subscriber** :
The node which consumes/receives the message published by the publisher, this is done via subscribing to the particular topic.

Now, let's see how to create a publisher and subscriber node in python

## Python Pub/Sub

### Create a python publisher node

We use the `create_publisher` method of the `Node` class in `rclpy` package. The method takes in 3 arguements and they are

- message type : the data type of the message, this needs to be specified for proper communication.
- topic name : the name of the topic to which the publisher is going to output the message
- queue size : for creating a buffer for the created messages

The code for creating a publisher node, let's say a `robot_news_station.py` inside the already created python package `my_py_pkg` is given below :

```python3
#!/usr/bin/python3
import rclpy
from rclpy.node import Node

# import the messge type from example interfaces
from example_interfaces.msg import String


class RobotNewsStationNode(Node):
    def __init__(self) -> None:
        super().__init__("robot_news_station")

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

```

### Create a python subscriber node

To create a subscriber node we make use of the `create_subscription` method present in the `Node` class. The code for creating a subscriber node is provided below.

```python3
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
```

After creating these node make sure to make it executable using `chmod +x` command and to add the executable path to the `setup.py` file. Then compile the package using `colcon build` command and we can also add the `--symlink-install` tag for easy debugging.

## Summary of python Node :

- Here we created two nodes, a publisher that publishes a `String` type message to a topic `robot_news`
- Another node, that subscribe to the topic `robot_news`
- The publisher publishes the message using a timer which invokes the callback function every 0.5 seconds
- The subscriber receives this message and it is logged in the console.
- We can also create a graph of the currently created nodes and topics and visualize how they publish and subcribe to the single `robot_news` topic, simply by using `rqt_graph` command to open the ROS dev tools.

## C++ Pub/Sub
