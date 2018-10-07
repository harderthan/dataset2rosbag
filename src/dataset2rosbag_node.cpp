#include "DataCombiner.hpp"
#include "YamlParamReader.hpp"

#include <ros/ros.h>

using namespace dataset2rogbag;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "dataset2rosbag_node");
    ros::NodeHandle nh;
    ros::NodeHandle private_nh("~");

    // Get params from yaml params
    cv::FileStorage *fs_pt;
    YamlParamReader param_reader(nh);
    param_reader.getFileStorage(fs_pt);

    DataContext context(fs_pt);

    return 0;

}


