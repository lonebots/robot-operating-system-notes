from launch import LaunchDescription 
from launch_ros.actions import Node

def generate_launch_description() :
    ld = LaunchDescription() 
    
    turtlesim_node = Node(
        package = 'turtlesim',
        executable = 'turtlesim_node',
        name = 'sim'
    )
    
    turtle_tf2_broadcaster_node = Node(
        package='learning_tf2_py',
        executable='turtle_tf2_broadcaster',
        name='broadcaster1',
        parameters=[
            {'turtle_name': 'turtle1'}
        ]
    )
    
    ld.add_action(turtlesim_node)
    ld.add_action(turtle_tf2_broadcaster_node)
    
    return ld 