import rclpy 
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
import math
import sys 
import numpy as np
from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster
from learning_tf2_py.helper import euler_to_quaternion

class StaticTransformPublisher(Node) :
    """
     Broadcasts transforms that never change between two coordinate frames.
    """
    
    def __init__(self, transformation) :
        super().__init__('static_transform_publisher') 
        self.tf_static_broadcaster = StaticTransformBroadcaster(self) # defines the transform broadcaster, it takes in Node, QoS profile, options as parameters 
        self.make_transform(transformation)
        
    def make_transform(self, transformation):
        """
        publish the static transforms provided 
        """
        t = TransformStamped()
        
        now = self.get_clock().now().to_msg()
        t.header.stamp = now
        t.header.frame_id = 'world'
        t.child_frame_id = transformation[1] 
        
        # set the transform x,y and z values
        t.transform.translation.x = float(transformation[2])
        t.transform.translation.y = float(transformation[3])
        t.transform.translation.z = float(transformation[4])
        
        quaternion = euler_to_quaternion(float(transformation[5]), float(transformation[6]), float(transformation[7]))
        
        t.transform.rotation.x = quaternion[0]
        t.transform.rotation.y = quaternion[1]
        t.transform.rotation.z = quaternion[2]
        t.transform.rotation.w = quaternion[3]
        
        # publish the tf using the broadcaster
        self.tf_static_broadcaster.sendTransform(t)

def main():
    logger = rclpy.logging.get_logger('logger')
    
    #obtain params from the commmand line arguements 
    if(len(sys.argv) != 8) :
        logger.info('Invalid number of parameters. Usage: \n'
                    '$ ros2 run learning_tf2_py static_turtle_tf2_broadcaster '
                    'child_frame_name x y z roll pitch yaw')
        sys.exit(1)
    
    if sys.argv[1] == 'world' :
        logger.info('Your static turtle name cannot be world')
        sys.exit(2)
        
    rclpy.init()
    node = StaticTransformPublisher(sys.argv)
    
    try :
        rclpy.spin(node)
    except KeyboardInterrupt :     
        pass
    
    rclpy.shutdown()

if __name__ == "__main__":  
    main() 