#include "YamlParamReader.hpp"

YamlParamReader::YamlParamReader(ros::NodeHandle &nh)
    :m_nh(nh){
    /* Read xml path from cmake's variables */
    std::string yaml_path;
    m_nh.param<std::string>("/param_yaml", yaml_path, STR(PARAM_YAML));
    m_fs = new cv::FileStorage(yaml_path, cv::FileStorage::READ);
    if(!m_fs->isOpened()){
        ROS_ERROR("%s : cannot open file", yaml_path.c_str());
        ros::shutdown();
    }
}

YamlParamReader::~YamlParamReader()
{
    delete m_fs;
}

cv::FileNode YamlParamReader::getFileNode(const std::string &node_name)
{
    cv::FileNode fn = m_fs->operator[](node_name);
    return fn;
}
