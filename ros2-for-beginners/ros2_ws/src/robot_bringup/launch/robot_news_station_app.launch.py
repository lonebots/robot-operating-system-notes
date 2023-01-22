from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

# news station nodes
    robot_news_station_giskard = Node(
        package="my_py_pkg",
        executable="robot_news_station",
        name="robot_news_station_giskard",
        parameters=[
            {"robot_name": "giskard"},
            {"publish_frequency ": 1.0}
        ]
    )

    robot_news_station_bb8 = Node(
        package="my_py_pkg",
        executable="robot_news_station",
        name="robot_news_station_bb8",
        parameters=[
                {"robot_name": "bb8"},
                {"publish_frequency ": 2.0}
        ]
    )

    robot_news_station_daneel = Node(
        package="my_py_pkg",
        executable="robot_news_station",
        name="robot_news_station_daneel",
        parameters=[
                {"robot_name": "daneel"},
                {"publish_frequency ": 3.0}
        ]
    )

    robot_news_station_jander = Node(
        package="my_py_pkg",
        executable="robot_news_station",
        name="robot_news_station_jander",
        parameters=[
                {"robot_name": "jander"},
                {"publish_frequency ": 4.0}
        ]
    )
    robot_news_station_c3po = Node(
        package="my_py_pkg",
        executable="robot_news_station",
        name="robot_news_station_c3po",
        parameters=[
                {"robot_name": "c3po"},
                {"publish_frequency ": 5.0}
        ]
    )

# smartphone nodes

    smartphone = Node(
        package="my_py_pkg",
        executable="smartphone"
    )

# add actions
    ld.add_action(robot_news_station_giskard)
    ld.add_action(robot_news_station_bb8)
    ld.add_action(robot_news_station_daneel)
    ld.add_action(robot_news_station_jander)
    ld.add_action(robot_news_station_c3po)
    ld.add_action(smartphone)
    return ld
