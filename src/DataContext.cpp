#include "DataContext.hpp"
#include <ros/package.h>
#include <iostream>

DataContext::DataContext(cv::FileStorage *_fs)
    :m_fs(*_fs)
{
    assert(checkVaild() && "Cannot read context from yaml params");

    // Check Camera Param
    cv::FileNode cam_fn = m_fs["camera"];
    if(cam_fn.isNone() == true)
        this->m_cam_flag = false;

    // Check GPS Param
    cv::FileNode gps_fn = m_fs["gps"];
    if(gps_fn.isNone() == true)
        this->m_gps_flag = false;
}

DataContext::~DataContext()
{}

bool DataContext::checkVaild()
{
    // TODO, Check params whether valid or not
    return true;
}

void DataContext::showParams()
{
    std::cout << "TODO, Show Parmas" << std::endl;
    return;
}

void DataContext::getBagPath(string &bag_path)
{
    string path;
    cv::FileNode fn = m_fs["bag"];
    if(fn.isNone() == false)
        path = ros::package::getPath("dataset2rosbag") + "/data/dataset2rosbag.bag";
    else
        path = ros::package::getPath("dataset2rosbag") + fn["path"];

    bag_path = path;
    return;
}

void DataContext::getSensorsFlags(SensorFlags &flags_st)
{
    flags_st.m_cam_flag = this->m_cam_flag;
    flags_st.m_gps_flag = this->m_gps_flag;

    return;
}

bool DataContext::getCamFrameName(string &frame_name)
{
    return true;
}

bool DataContext::getCamFrameTime(string &frame_time)
{
    return true;
}

bool DataContext::getGpsFrameName(string &frame_name)
{
    return true;
}

bool DataContext::getGpsFrameTime(string &frame_time)
{
    return true;
}
