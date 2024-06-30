import math
import rclpy
from rclpy.node import Node 
from tf2_ros import TransformException
from tf2_ros.transform_listener import TransformListener
from tf2_ros.buffer import Buffer
from geometry_msgs.msg import Twist 
from turtlesim.srv import Spawn

class FrameListener(Node) :
    def __init__(self,) :
        super().__init__('turtle_tf2_transform_listener')
        
        # set the targe frame; required while getting the transform 
        self.target_frame = self.declare_parameter('target_frame', 'turtle1').get_parameter_value().string_value
        
        # intialize spawner 
        self.spawner = self.create_client(Spawn, 'spawn')
        
        # for transform lister; we need a buffer and pass entire node to the listener 
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        
        # check variables
        self.turtle_spawning_service_ready = False 
        self.turtle_spawned = False 
        
        # cmd_vel publisher 
        self.publisher = self.create_publisher(Twist, '/turtle2/cmd_vel', 1)
        
        # timer 
        self.timer = self.create_timer(1.0, self.timer_callback)
        
    def timer_callback(self) :
        # set the from and to rel frames for computing transformations
        from_frame_rel = self.target_frame
        to_frame_rel = 'turtle2' 
        
        if self.turtle_spawning_service_ready :
            if self.turtle_spawned :
                # do the transform computation and publish cmd_vel 
                self.get_logger().info('inside all done')
                try : 
                    t = self.tf_buffer.lookup_transform(
                        to_frame_rel,
                        from_frame_rel,
                        rclpy.time.Time())
                except TransformException as ex : 
                    self.get_logger.error(f'Could not transform {to_frame_rel} to {from_frame_rel} : {ex}')
                    
                msg = Twist()
                
                # set the message parameters x & theta 
                scale_rotation_rate = 1.0
                msg.angular.z = scale_rotation_rate * math.atan2(t.transform.translation.y, t.transform.translation.x)
                
                scale_forward_speed = 0.5
                msg.linear.x = scale_forward_speed * math.sqrt(t.transform.translation.x ** 2 + t.transform.translation.y ** 2)
                
                self.publisher.publish(msg)
                self.get_logger().info('twist message published'+ str(msg))
                
            else :
                if self.result.done():
                    self.get_logger().info(f'Successfully spawned {self.result.result().name}')
                    self.turtle_spawned = True
                else :
                    self.get_logger.info('Spawn not finished.')
        else : 
            if self.spawner.service_is_ready() :
                # initialize the Spawn request 
                request = Spawn.Request()
                request.name = 'turtle2' 
                request.x = float(4)
                request.y = float(2)
                request.theta = float(0)
                
                self.result = self.spawner.call_async(request)
                self.turtle_spawning_service_ready = True
            else :
                self.get_logger.info('Spawn service is unavailable')

def main(args = None) :
    rclpy.init()
    node = FrameListener() 
    
    try :
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass 
    
    rclpy.shutdown()

if __name__ == "__main__" :
    main()