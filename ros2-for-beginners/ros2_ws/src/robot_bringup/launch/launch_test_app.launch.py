from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    # python_oop_node
    python_oops_node = Node(
        package="my_py_pkg",
        executable="my_oops_node",
        name="my_python_oops_node"
    )

    # robot_news station
    robot_news_station = Node(
        package="my_cpp_pkg",
        executable="robot_news_station",
        name="yoyo_news_robot"
    )

    ld.add_action(python_oops_node)
    ld.add_action(robot_news_station)

    return ld
