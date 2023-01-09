#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node{
    public:
        MyNode() : Node("cpp_oops_test"), counter_(0)
        {
            RCLCPP_INFO(this->get_logger(),"Hello from C++ oops Node!");

            // initialize the timer
            timer_ = this->create_wall_timer(std::chrono::seconds(1),
            std::bind(&MyNode::timerCallback, this));  // function binding to the class instance using 'this' keyword
        }

    private :

    // create timer callback to implement a counter 
    void timerCallback (){
        counter_ ++;
        RCLCPP_INFO(this->get_logger(),"Hello count value : %d",counter_);
    }

    // create the timer 
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;
};

int main(int argc , char **argv) {
    rclcpp::init(argc,argv);

    auto node = std::make_shared<MyNode>( );

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}