from launch import LaunchDescription 
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

def generate_launch_description() :
    ld = LaunchDescription() 
    
    turtlesim_node = Node(
        package = 'turtlesim',
        executable = 'turtlesim_node',
        name = 'sim'
    )
    
    # broadcast tf for turtle 1 
    turtle_tf2_broadcaster_node1 = Node(
        package='learning_tf2_py',
        executable='turtle_tf2_broadcaster',
        name='broadcaster1',
        parameters=[
            {'turtle_name': 'turtle1'}
        ]
    )
    
    # broadcast tf for turtle2 
    turtle_tf2_broadcaster_node2 = Node(
        package = 'learning_tf2_py',
        executable = 'turtle_tf2_broadcaster',
        name = 'broadcaster2',
        parameters =[
            {'turtle_name' : 'turtle2'}
        ]
    )
    
    declare_target_frame_launch_argument = DeclareLaunchArgument(
        'target_frame',
        default_value = 'turtle1',
        description = 'Target frame name'
    )
    
    # listener node 
    turtle_tf2_listener_node = Node(
        package = 'learning_tf2_py',
        executable = 'turtle_tf2_listener',
        name = 'listener',
        parameters = [
            {'target_frame' : LaunchConfiguration('target_frame')}
        ]
        
    )
    
    ld.add_action(turtlesim_node)
    ld.add_action(turtle_tf2_broadcaster_node1)
    ld.add_action(turtle_tf2_broadcaster_node2)
    ld.add_action(declare_target_frame_launch_argument)
    ld.add_action(turtle_tf2_listener_node)
    
    return ld 