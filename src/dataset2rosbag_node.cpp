#include "YamlParamReader.hpp"
#include <ros/ros.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "dataset2rosbag_node");
    ros::NodeHandle nh;
    ros::NodeHandle private_nh("~");

    YamlParamReader param_reader(nh);

    std::string node_name = "camera";
    cv::FileNode fn = param_reader.getFileNode(node_name);
/*
    std::string topic_name = std::string(fn["topic_name"]);
    int test1      = fn["test1"];

    ROS_INFO("%s", topic_name.c_str());
    ROS_INFO("%d", test1);
*/
    return 0;
}
