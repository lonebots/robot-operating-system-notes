#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp" 

using std::placeholders::_1;
using std::placeholders::_2;

class AddTwoIntsServerNode : public rclcpp::Node{
    public:
        AddTwoIntsServerNode() : Node("add_two_ints_server") {

            server_ = this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints",
            std::bind(&AddTwoIntsServerNode::callbackAddTwoInts,this,_1,_2));

            RCLCPP_INFO(this->get_logger(),"cpp add two ints server started");
        }

    private:

    // callback
    // params -> req, res
    void callbackAddTwoInts(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
    const example_interfaces::srv::AddTwoInts::Response::SharedPtr response){
            // compute sum
            response->sum = request->a + request->b;
            RCLCPP_INFO(this->get_logger(),"%ld + %ld = %ld",request->a,request->b,response->sum);
    }

    // make a server variable - declaration
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_; 


};


int main(int argc, char **argv){
    rclcpp::init(argc,argv);
    auto node = std::make_shared<AddTwoIntsServerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}