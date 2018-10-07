#ifndef DATA_CONTEXT_HPP_
#define DATA_CONTEXT_HPP_
#include "Common.hpp"

#include <opencv2/core.hpp>
#include <fstream>
#include <string>

using namespace dataset2rogbag;
using namespace std;

namespace dataset2rogbag {
class DataContext
{
public:
    DataContext(cv::FileStorage *_fs);
    ~DataContext();

    void showParams();

    void getSensorsFlags(SensorFlags &flags_st);
    void getBagPath(string &bag_path);

    // Member Functions For Camera
    bool getCamFrameName(string &frame_name);
    bool getCamFrameTime(string &frame_time);

    // Members For GPS
    bool getGpsFrameName(string &frame_name);
    bool getGpsFrameTime(string &frame_time);

private:
    bool checkVaild();

    cv::FileStorage m_fs;
    string m_data_type;

    // Members Variables For Camera
    bool m_cam_flag;
    int m_cam_frame_count;
    string m_cam_frame_path;
    string m_cam_frame_prefix;
    string m_cam_frame_format;
    string m_cam_frame_time;
    ifstream m_cam_time_stream;

    // Members Variables For GPS
    bool m_gps_flag;
};
}
#endif // DATA_CONTEXT_HPP_
