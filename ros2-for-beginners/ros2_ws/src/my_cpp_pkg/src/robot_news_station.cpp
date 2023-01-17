#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RobotNewsStationNode: public rclcpp::Node{
    public:
        RobotNewsStationNode() : Node("robot_news_station") ,robot_name_("R2D2"){
            /*
            initialize publisher
            takes in two parameters 
                1. topic name
                2. queue size

                the message type is already specified in the create_publisher template
            */ 
            
            publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news",10);

            // initialize timer 
            timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
            std::bind(&RobotNewsStationNode::publishNews,this));

            // node start log 
            RCLCPP_INFO(this->get_logger(),"cpp robot news station has been started");
        };

    private:
    // declarations
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_; //publisher 
    std::string robot_name_; //robot name
    rclcpp::TimerBase::SharedPtr timer_; //timer

    // function to publish
    void publishNews(){
        auto msg = example_interfaces::msg::String();
        msg.data = std::string("Hi this is "+robot_name_+"from robot news");
        publisher_->publish(msg);
    };


};


int main(int argc, char **argv) {
    rclcpp::init(argc,argv);
    auto node = std::make_shared<RobotNewsStationNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}