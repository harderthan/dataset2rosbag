#include "YamlParamReader.hpp"

YamlParamReader::YamlParamReader(ros::NodeHandle &nh)
    :m_nh(nh){
    // Read xml path from cmake's variables
    std::string yaml_path;
    m_nh.param<std::string>("/param_yaml", yaml_path, STR(PARAM_YAML));
    m_fs = new cv::FileStorage(yaml_path, cv::FileStorage::READ);
    assert(m_fs->isOpened() && "Cannot open file");
}

YamlParamReader::~YamlParamReader()
{
    delete m_fs;
}

void YamlParamReader::getFileStorage(cv::FileStorage *fs)
{
    fs = m_fs;
}
