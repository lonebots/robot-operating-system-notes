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