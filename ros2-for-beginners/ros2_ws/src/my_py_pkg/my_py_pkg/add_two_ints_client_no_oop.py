#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


def main(args=None):
    rclpy.init(args=args)
    node = Node("add_two_ints_no_oop")

    """
    create a client
        takes in 2 parameters 
            1. service type 
            2. service name
    """
    client = node.create_client(AddTwoInts, "add_two_ints")

    # wait for server
    while not client.wait_for_service(1.0):
        node.get_logger().warn("waiting for service add two ints...")

    # exit while
    node.get_logger().info("\n<-- server connected successfully -->")

    # create a request object using AddTwoInts
    request = AddTwoInts.Request()
    request.a = int(input('enter number 1 :'))
    request.b = int(input('enter number 2 :'))

    """
    call function types 
        1. call
        2. call_async

        wait for the call to succeed and the future has a value from the response 
        - spin the node until the future gets a value
            spin_until_future_complete 
                takes 2 arguements 
                    1. node -> for referring to the currently created node 
                    2. future -> for waiting until it has a value

            in the future the result object contains the actual response from the server
    """
    future = client.call_async(request)
    rclpy.spin_until_future_complete(node, future)

    # take out result from the future using try except
    try:
        response = future.result()
        node.get_logger().info(f"{request.a} + {request.b} = {response.sum}")
    except Exception as e:
        node.get_logger().error(f"service call failed : {e}")

    rclpy.shutdown()


if __name__ == "__main__":
    main()
