#include "DataCombiner.hpp"
#include <opencv2/highgui/highgui.hpp>

DataCombiner::DataCombiner(DataContext *context)
    :m_context(context)
{
    bool status = false;

    // Get a Flags Structor for Sensors
    SensorFlags flags_st;
    this->m_context->getSensorsFlags(flags_st);
    this->m_cam_flag = flags_st.m_cam_flag;
    this->m_gps_flag = flags_st.m_gps_flag;

    // Initialize ros::bag for writing data
    string bag_path;
    m_context->getBagPath(bag_path);
    m_bag.open(bag_path.c_str(), rosbag::bagmode::Write);
    assert(status);
}

DataCombiner::~DataCombiner(){}

void DataCombiner::combinePipeLine()
{
    bool status = true;

    // Combine camera data
    status = true;
    if(m_cam_flag == true){
        while(status){
            status = this->readCamData();
            if(status)
                status = this->writeCamData();
        }
    }

    // Combine gps data
    status = true;
    if(m_gps_flag == true){
        while(status){
            status = this->readGpsData();
            if(status)
                status = this->writeGpsData();
        }
    }
}

bool DataCombiner::readCamData()
{
    string frame_name;
    if(m_context->getCamFrameName(frame_name) == false)
        return false;

    string frame_time;
    if(m_context->getCamFrameTime(frame_time) == false)
        return false;

    // TODO, Copy a image frame to member from context

    return true;
}

bool DataCombiner::readGpsData()
{
    string frame_name;
    if(this->m_context->getGpsFrameName(frame_name) == false)
        return false;

    string frame_time;
    if(this->m_context->getGpsFrameTime(frame_time) == false)
        return false;

    // TODO, Copy a gps frame to member from context

    return true;
}

bool DataCombiner::writeCamData()
{
    // Write a Image on ros::bag
    return true;
}

bool DataCombiner::writeGpsData()
{
    // Write a Position on ros::bag
    return true;
}

/*
struct time_stamp
{
    int hour = 0;
    int min  = 0;
    int sec  = 0;
    int nsec = 0;
};

bool writeCamera(rosbag::Bag &bag, const cv::FileNode &fn)
{
    // open the timestamp file
    std::ifstream time_file(ros::package::getPath("dataset2rosbag") + fn["path"] + "/timestamps.txt");

    // Loop
    std::vector<std::pair<ros::Time,time_stamp>> time_vec;
    std::string timestemp_buf;

    if(std::getline(time_file, timestemp_buf)){ // idx == 0
        time_stamp ts;
        ts.hour = 0;
        ts.min = 0;
        ts.sec = 0;
        ts.nsec = 0;

        time_vec.push_back(std::make_pair(ros::Time::now(),ts));
    }
    else // There is no line on stamp's file
        return false;

    int idx = 1;
    while(std::getline(time_file, timestemp_buf)){
        // get a time stamp
        time_stamp ts;
        ts.hour = std::atoi(timestemp_buf.substr(11,2).c_str());
        ts.min  = std::atoi(timestemp_buf.substr(14,2).c_str());
        ts.sec  = std::atoi(timestemp_buf.substr(17,2).c_str());
        ts.nsec = std::atoi(timestemp_buf.substr(20.9).c_str());

        time_stamp pre_ts = time_vec[idx-1].second;

        uint32_t sec = (pre_ts.hour - ts.hour)*3600 + (ts.min - pre_ts.min)*60 + (ts.sec - pre_ts.sec);
        uint32_t nsec;
        if(ts.nsec > pre_ts.nsec)
            nsec = ts.nsec - pre_ts.nsec;
        else
            nsec = 1000000000 - pre_ts.nsec + ts.nsec;

        ros::Time rt = time_vec[idx-1].first;
        rt.sec += sec;
        rt.nsec += nsec;

        ROS_INFO("%d.%d", rt.sec, rt.nsec);

        time_vec.push_back(std::make_pair(rt, ts));

        ++idx;
    }

    char file_prefix[256];

    cv::Mat image;

    int frame_idx = 0;
    ros::Time time = ros::Time::now();
    int pre_hour = 0, pre_min = 0, pre_sec = 0, pre_nsec = 0;
    while(std::getline(time_file, timestemp_buf))
    {
        // get a image frame
        std::sprintf(file_prefix, "/data/%010d", frame_idx);
        std::string file_full_path= ros::package::getPath("dataset2rosbag") + fn["path"] + file_prefix + ".png";
//        ROS_INFO("%s", file_full_path.c_str());

        image = cv::imread(file_full_path, CV_LOAD_IMAGE_COLOR);
        if(image.empty())
        {
            ROS_INFO("%s, End of File", file_full_path.c_str());
            break;
        }

        ++frame_idx;
    }

//    bag.write(fn["topic_name"], ros::Time::now(), data);

    bag.close();
}
*/


