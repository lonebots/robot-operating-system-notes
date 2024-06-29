import rclpy
from geometry_msgs.msg import TransformStamped
from rclpy.node import Node
from tf2_ros import TransformBroadcaster
from learning_tf2_py.helper import euler_to_quaternion
from turtlesim.msg import Pose

class FramePublisher(Node) :
    def __init__(self,) :
        super().__init__('turtle_tf2_frame_publisher') 
        
        # get the turtle name from launch argument
        self.turtle_name = self.declare_parameter('turtle_name', 'turtle').get_parameter_value().string_value
        
        # initialize the transfrom broadcaster 
        self.transform_broadcaster = TransformBroadcaster(self)
        
        # subscribe to turtle pose and broadcast it postion and orientation 
        topic = f'/{self.turtle_name}/pose'
        self.subscription = self.create_subscription(Pose, topic, self.handle_turtle_pose, 1) 
        
        # prevent unused variable warning
        self.subscription
        self.get_logger().info('turtle_tf2_frame_publisher_initialized.')
        
    def handle_turtle_pose(self, msg) :
        t = TransformStamped()
        
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'world'
        t.child_frame_id = self.turtle_name
        
        # since turtle exist only in x y plane z is 0
        t.transform.translation.x = msg.x 
        t.transform.translation.y = msg.y 
        t.transform.translation.z = 0.0
        
        # quaternions
        q = euler_to_quaternion(0.0, 0.0, msg.theta) # turtle turns only around z axis
        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.z = q[3] 
        
        self.transform_broadcaster.sendTransform(t)

def main(args = None) :
    rclpy.init() 
    node = FramePublisher()
    
    try :
        rclpy.spin(node)
    except KeyboardInterrupt :
        pass 
    
    rclpy.shutdown() 


if __name__ == "__main__" :
    main()