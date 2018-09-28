#ifndef PARAM_READER_HPP_
#define PARAM_READER_HPP_
#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <ros/console.h>
#include <string>

#define XSTR(x) #x
#define STR(x) XSTR(x)

class YamlParamReader{
public:
    YamlParamReader(ros::NodeHandle &nh);
    ~YamlParamReader();
    cv::FileNode getFileNode(const std::string &node_name);
private:
    ros::NodeHandle m_nh;
    cv::FileStorage *m_fs;
};
#endif // PARAM_READER_HPP_
