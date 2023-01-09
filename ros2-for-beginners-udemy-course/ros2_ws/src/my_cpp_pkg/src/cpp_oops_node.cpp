#include "rclcpp/rclcpp.hpp"

int main(int argc , char **argv) {
    rclcpp::init(argc,argv);

    auto node = std:make_shared<rclcpp::Node>("cpp_opps_test");

    RCLCPP_INFO(node->get_logger(),"Hello from C++ oops Node!");

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}