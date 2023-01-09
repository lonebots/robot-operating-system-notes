#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    // initialise ros2 communication
    rclcpp::init(argc,argv);

    /*
    after writing the program we have to compile it create a node
    std::make_shared<> creates a shared pointer 
    ros2 use share pointer almost every where
    whene pointer goes out of scope it will be automatically destoryed along with that the node also get destroyed
    */
    auto node = std::make_shared<rclcpp::Node>("cpp_test");

    // log to terminal
    RCLCPP_INFO(node->get_logger(),"Hello CPP Node");

    /* 
    spin the node
    the node won't be killed and it live continuously
    */
    rclcpp::spin(node);

    // shutdown ros2 communication
    rclcpp::shutdown();
    return 0;
}


/*
after writing the program we have to 
    1. compile it
    2. install it using CMakeList.txt
*/ 