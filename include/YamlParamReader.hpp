#ifndef YAML_PARAM_READER_HPP_
#define YAML_PARAM_READER_HPP_
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
    void getFileStorage(cv::FileStorage *fs);
private:
    ros::NodeHandle m_nh;
    cv::FileStorage *m_fs;
};
#endif // YAML_PARAM_READER_HPP_
