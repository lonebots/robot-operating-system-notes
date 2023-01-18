#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from functools import partial

from example_interfaces.srv import AddTwoInts


class AddTwoIntClient(Node):
    def __init__(self) -> None:
        super().__init__('add_two_ints_client')
        self.get_logger().info("python add two int client started")

        # call the function to invoke server functionalities
        self.call_add_two_ints_server()

    # function to call the server
    def call_add_two_ints_server(self):
        # arg: service_type,service_name
        client = self.create_client(AddTwoInts, "add_two_ints")

        # wait for server
        while not client.wait_for_service(1.0):
            self.get_logger().warn("waiting for add two ints server . . .")

        self.get_logger().info("<-- server available -->")

        # create a request
        a = int(input('enter number 1 : '))
        b = int(input('enter number 2 : '))
        request = AddTwoInts.Request()
        request.a = a
        request.b = b

        # call async and get it to future
        future = client.call_async(request)

        # add callback
        future.add_done_callback(partial(self.callback_add_two_ints, a=a, b=b))

    def callback_add_two_ints(self, future, a, b):
        try:
            response = future.result()
            self.get_logger().info(f"{a} + {b} = {response.sum}")
        except Exception as e:
            self.get_logger().info(f"service call failer with exception : {e}")


def main(args=None):
    rclpy.init()
    node = AddTwoIntClient()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
