import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():

    use_sim_time = LaunchConfiguration("use_sim_time", default="false")

    urdf_file_name = "r2d2.urdf.xml"
    rviz_config = 'r2d2_config.rviz'
    urdf_tutorial_r2d2 = get_package_share_directory('urdf_tutorial_r2d2')
    urdf = os.path.join(urdf_tutorial_r2d2, urdf_file_name)
    rviz_config_file = os.path.join(urdf_tutorial_r2d2, rviz_config)
    
    print(rviz_config_file)


    with open(urdf, "r") as infp:
        robot_desc = infp.read()

    ld = LaunchDescription()

    use_sim_time_launch_arguement = DeclareLaunchArgument(
        "use_sim_time",
        default_value="false",
        description="Use simulation (Gazebo) clock if true",
    )
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher_node",
        output="screen",
        parameters=[{"use_sim_time": use_sim_time, "robot_description": robot_desc}],
        arguments=[urdf],
    )
    r2d2_state_publisher_node = Node(
        package="urdf_tutorial_r2d2",
        executable="state_publisher",
        name="r2d2_state_publishser",
        output="screen",
    )
    
    rviz2 = Node(
        package = 'rviz2',
        executable = 'rviz2',
        output = 'screen',
        arguments = ['-d', rviz_config_file]
    )

    ld.add_action(use_sim_time_launch_arguement)
    ld.add_action(robot_state_publisher_node)
    ld.add_action(r2d2_state_publisher_node)
    ld.add_action(rviz2)

    return ld
