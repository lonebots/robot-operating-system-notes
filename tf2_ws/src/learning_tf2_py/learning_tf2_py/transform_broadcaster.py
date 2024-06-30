from geometry_msgs.msg import TransformStamped
import rclpy
from rclpy.node import Node
from tf2_ros import TransformBroadcaster
from turtlesim.msg import Pose
from learning_tf2_py.helper import euler_to_quaternion

class FramePublisher(Node):

    def __init__(self):
        super().__init__('turtle_tf2_frame_publisher')
        self.turtlename = self.declare_parameter('turtlename', 'turtle').get_parameter_value().string_value

        self.tf_broadcaster = TransformBroadcaster(self)
        self.subscription = self.create_subscription(Pose, f'/{self.turtlename}/pose', self.handle_turtle_pose,)
        self.subscription  

    def handle_turtle_pose(self, msg):
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'world'
        t.child_frame_id = self.turtlename

        t.transform.translation.x = msg.x
        t.transform.translation.y = msg.y
        t.transform.translation.z = 0.0

        q = euler_to_quaternion(0, 0, msg.theta)
        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]

        self.tf_broadcaster.sendTransform(t)


def main():
    rclpy.init()
    node = FramePublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()