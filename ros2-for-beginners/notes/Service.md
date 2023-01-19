# Service in ROS2

This is another method for communication between nodes in ros2. This works like a request/response model. The system contains the following setup;

- client
- server

It is mainly used when we need a client-server architecture, for performing **actions** and **computations**.

The system constraints are :

- A single service must have only one server (a single service server)
- A service can be untilised by multiple clients.
- The communication can be either synchronous or asynchronous.
- The client and server message type may or maynot be the same.

## Python server client

### python service server

The server is setup using the `create_service` method of the `Node` class in `rclpy`. basic server code is provided here. create file in the `src` folder of the ros workspace, include the executable entry point in the `setup.py` file.

```python3
#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class AddTwoIntNode(Node):
    def __init__(self) -> None:
        super().__init__("add_two_ints_server")
        self.server_ = self.create_service(
            AddTwoInts, "add_two_ints", self.callback_add_two_ints)

        self.get_logger().info("<-- python add ints server started -->")

    def callback_add_two_ints(self, request, response):
        response.sum = request.a + request.b
        self.get_logger().info(f"{request.a} + {request.b} = {request.sum}")
        return response

def main(args=None):
    rclpy.init()
    node = AddTwoIntNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
```

### Interacting with service from terminal

The service can be invoked directly from the terminal using the `ros2 service`. We can try out the following option for the `service` command.

```bash
# list all the available services
ros2 service list 

# call a running service from the terminal
# ros2 service call <name_of_service> <type_of_service> "{key:value}"
ros2 service call /add_two_ints example_interfaces/srv/AddTwoInts "{a : 2, b : 3}"
```

Make sure that the server is running and the output of the above request is as below:

```bash
requester: making request: example_interfaces.srv.AddTwoInts_Request(a=2, b=3)

response:
example_interfaces.srv.AddTwoInts_Response(sum=5)
```

## Python client 

we make use of the `create_client` method of the `Node` class

**code**

### With out OOPs

```python3
#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts


def main(args=None):
    rclpy.init(args=args)
    node = Node("add_two_ints_no_oop")

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
```

### With OOPs

when using oops we cannot call the `spin_until_future_complete` from within a class object, we need to handle it differently. 
- we add a callback to the `future` object and which is called when the future is done

**Code** 

```python3
#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from functools import partial
from example_interfaces.srv import AddTwoInts

class AddTwoIntClient(Node):
    def __init__(self) -> None:
        super().__init__('add_two_ints_client')
        self.get_logger().info("python add two int client started")
        self.call_add_two_ints_server()

    def call_add_two_ints_server(self):
        client = self.create_client(AddTwoInts, "add_two_ints")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("waiting for add two ints server . . .")

        self.get_logger().info("<-- server available -->")

        a = int(input('enter number 1 : '))
        b = int(input('enter number 2 : '))
        request = AddTwoInts.Request()
        request.a = a
        request.b = b
        future = client.call_async(request)
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
```


# C++ client/server

## with no OOPs

**code**

```cpp
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp" 

#include <cstdlib>

int main(int argc, char **argv){
    rclcpp::init(argc,argv);


    if(argc !=3) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"usage : add_two_ints_client_no_oop X Y");
        return 1;
    }
    
    auto node = std::make_shared<rclcpp::Node>("add_two_ints_client_no_opp");
    /*
        create a client 
        send request 
        wait for the response 
    */
    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
    while(!client->wait_for_service(std::chrono::seconds(1))){
        RCLCPP_WARN(node->get_logger(),"cpp client waiting for add to int server");
    }

    RCLCPP_INFO(node->get_logger(),"<-- service available -->");

    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = atoll(argv[1]);
    request->b = atoll(argv[2]);

    auto future = client->async_send_request(request);
    if(rclcpp::spin_until_future_complete(node,future) == rclcpp::FutureReturnCode::SUCCESS){
        RCLCPP_INFO(node->get_logger(),"%ld + %ld = %ld",request->a,request->b,future.get()->sum);
    }
    else{
        RCLCPP_ERROR(node->get_logger(),"Failed to call service add_two_ints");
    }

    
    rclcpp::shutdown();
    return 0;
}
```