from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    ld = LaunchDescription()

    planner_ask_node = Node(
        package="my_intermediate",
        executable="fake_asker",
        name="fake_asker",
        parameters=[
            {"n": 2},
            {"x_start": [-1.5, -1.5]},
            {"y_start": [-0.5, 0.5]},
            {"z_start": [0.0, 0.0]},
            {"x_end": [-1.5, -1.5]},
            {"y_end": [0.8, -0.8]},
            {"z_end": [0.0, 0.0]}
        ]
    )

    ld.add_action(planner_ask_node)
    
    return ld