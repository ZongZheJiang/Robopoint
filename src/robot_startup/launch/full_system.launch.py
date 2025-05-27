from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    realsense_camera_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            FindPackageShare('realsense2_camera'),
            '/launch/rs_launch.py'
        ]),
        launch_arguments={
            'pointcloud.enable': 'true',       
            'align_depth.enable': 'true',     
            'enable_sync': 'true', 
            'depth_module.profile': '640x480x30', 
            'rgb_camera.profile': '640x480x30',
            'initial_reset': 'true'
            # You can find available parameters by running:
            # ros2 launch realsense2_camera rs_launch.py --show-args
        }.items()
    )

    image_projector_node = Node(
        package='image_projector',
        namespace='image_projector', # Namespacing helps avoid topic/service clashes
        executable='image_projector',
        output='screen'
    )

    movearm_node = Node(
        package='py_movearm',
        namespace='py_movearm',
        executable='move_arm',
        output='screen'
    )

    query_node = Node(
        package='robopoint_llm',
        namespace='robopoint_llm',
        executable='query',
        output='screen'
    )

    ld = LaunchDescription()

    ld.add_action(realsense_camera_launch)
    ld.add_action(image_projector_node)
    ld.add_action(query_node)
    ld.add_action(movearm_node)

    return ld