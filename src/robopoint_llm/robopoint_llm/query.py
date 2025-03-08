from robopoint_interfaces.srv import Query, MoveToPoint

import rclpy
from rclpy.node import Node
from realsense2_camera_msgs.msg import RGBD
from cv_bridge import CvBridge
from torch import rsub
from transformers.models import llama
from robopoint.run_llm_service import llm_service

# deps to convert cv2 to PIL
import cv2
from PIL import Image
import numpy as np

# CLI tools
import sys
import argparse

class QueryService(Node):
    """Gets an image from the RGBD node and passes it to the LLM calling node"""
    def __init__(self, query=None, filepath=None):
        super().__init__('query_service_node')
        # debug args
        self.query = query
        self.filepath = filepath

        # Subscribe to the RGBD topic
        self.subscription = self.create_subscription(
            RGBD,
            '/camera/camera/rgbd',
            self.listener_callback,
            1 # only need the latest image
        )
        self.bridge = CvBridge()
        self.rgb_image = None
        self.move_to_point_client = self.create_client(MoveToPoint, 'move_to_point')
        self.srv = self.create_service(Query, 'query_service', self.query_callback)

    def listener_callback(self, msg: RGBD):
        '''Callback function for the RGBD subscriber to receive RGB and depth images.'''
        try:
            self.rgb_image = self.bridge.imgmsg_to_cv2(msg.rgb, desired_encoding='bgr8')
            self.get_logger().info("Received RGB image")
        except Exception as e:
            self.get_logger().error("Error converting RGB image: {}".format(e))
            return

    def query_callback(self, request, response):
        '''Callback function for the query service to receive a query and return a response.'''
        self.get_logger().info(f'Incoming query (prompt)\n-----\n{request.query}')

        if self.rgb_image is None:
            self.get_logger().error("No RGB image received yet")
            return response

        # Convert to PIL image for downstream processing
        img = Image.fromarray(cv2.cvtColor(self.rgb_image, cv2.COLOR_BGR2RGB))

        x, y = llm_service.generate(request.query if self.query != None else self.query, [img]) # returned as normalized coordinates from 0 to 1

        # Save debug image
        if self.filepath:
            llm_service.process_and_visualize_output([x,y], img, self.filepath)
        # Pass coordinates downstream
        move_to_point_request = MoveToPoint.Request()
        move_to_point_request.x = x
        move_to_point_request.y = y
        future = self.move_to_point_client.call_async(move_to_point_request) # the next stage of the pipeline in move_arm.py
        # by right, future returns no result, since the action is that the robot moves.
        return response


def main(args=None):
    if args is None:
        args = sys.argv[1:]
    parser = argparse.ArgumentParser(description='Query service node')
    parser.add_argument('--query', type=str, help='Query to pass to the LLM model. Enclose in quotation marks')
    parser.add_argument('--filepath', type=str, help='Absolute filepath to save a debug image to')
    parsed_args = parser.parse_args(args)

    rclpy.init()

    query_service = QueryService(parsed_args.query, parsed_args.filepath)

    rclpy.spin(query_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
