#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
#include <cstdlib>

class AddTwoIntsClientNode : public rclcpp::Node
{
public:
    AddTwoIntsClientNode(int a, int b, int argc) : Node("add_two_ints_client")
    {
        RCLCPP_INFO(this->get_logger(), "cpp add two ints client started");

        // we need to call the callback from different frame / thread inorder for function to not block the class constructor
        thread1_ = std::thread(std::bind(&AddTwoIntsClientNode::callAddTwoIntsServie, this, a, b));
    }

    void callAddTwoIntsServie(int a, int b)
    {
        auto client = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
        while (!client->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_INFO(this->get_logger(), "waiting for server to be up ...");
        }

        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = a;
        request->b = b;

        auto future = client->async_send_request(request);
        /*wait until the future has a response values and can handle exception*/

        try
        {
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(), "%d + %d = %ld ", a, b, response->sum);
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "service call failed");
        }
    }

private:
    //  create a new thread
    std::thread thread1_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    if (argc != 3)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "usage : add_two_ints_client A B");
    }
    auto node = std::make_shared<AddTwoIntsClientNode>(atoll(argv[1]), atoll(argv[2]), argc);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}