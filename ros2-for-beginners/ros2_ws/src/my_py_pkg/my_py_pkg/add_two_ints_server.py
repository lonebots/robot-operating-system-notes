#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


class AddTwoIntNode(Node):
    def __init__(self) -> None:
        super().__init__("add_two_ints_server")

        """
        create a service server instance 
            - using create_service method in Node class
                --> takes in 3 arguements
                    1. service message type
                    2. service name
                    3. callback function - for handling the request to the server 

        """
        self.server_ = self.create_service(
            AddTwoInts, "add_two_ints", self.callback_add_two_ints)

        self.get_logger().info("<-- python add ints server started -->")

    """
    call back function for handling the request and responding to it 
    it takes 2 parameters 
        1. request 
        2. response 
    """

    def callback_add_two_ints(self, request, response):
        response.sum = request.a + request.b
        self.get_logger().info(f"{request.a} + {request.b} = {response.sum}")
        return response


def main(args=None):
    rclpy.init()
    node = AddTwoIntNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
