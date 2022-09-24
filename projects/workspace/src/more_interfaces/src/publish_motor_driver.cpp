#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "more_interfaces/msg/motor_driver.hpp"

using namespace std::chrono_literals;

    class MotorDriverPublisher : public rclcpp::Node
{
public:
    MotorDriverPublisher()
        : Node("motor_driver_publisher")
    {
        motor_driver_publisher_ =
            this->create_publisher<more_interfaces::msg::MotorDriver>("motor_driver", 10);

        auto publish_msg = [this]() -> void
        {
            auto message = more_interfaces::msg::MotorDriver();

            message.device_id = "mtdv01";
            message.rot_ang = 30;
            message.power_in = 2;
            message.rpm = 300;

            std::cout << "Publishing motor driver \n device_id : " << message.device_id << "rpm :" << message.rpm << std::endl;

            this->motor_driver_publisher_->publish(message);
        };
        timer_ = this->create_wall_timer(1s, publish_msg);
    }

private:
    rclcpp::Publisher<more_interfaces::msg::MotorDriver>::SharedPtr motor_driver_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

// main function
int
main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MotorDriverPublisher>());
    rclcpp::shutdown();

    return 0;
}