#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class SmartPhoneNode : public rclcpp::Node
{

public:
    SmartPhoneNode() : Node("smartphone")
    {

        /*
        initialize subscriber
            the function takes in 3 parameters they are
                1. topic name
                2. queue size
                3. callback --> additional code required since the callback function takes in parameters.
        */
        subscriber_ = this->create_subscription<example_interfaces::msg::String>("robot_news", 10,
                                                                                 std::bind(&SmartPhoneNode::callbackRobotNews, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "cpp smartphone node has been started");
    }

private:
    // call back for handling subscription
    void callbackRobotNews(const example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }

    // declaration
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;

};

int
main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<SmartPhoneNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}