#ifndef DATA_COMBINER_HPP_
#define DATA_COMBINER_HPP_
#include "DataContext.hpp"
#include <opencv2/core.hpp>
#include <rosbag/bag.h>

using namespace dataset2rogbag;

namespace dataset2rogbag {
class DataCombiner
{
public:
    DataCombiner(DataContext *context);
    ~DataCombiner();
    void combinePipeLine();

private:
    bool readCamData();
    bool readGpsData();

    bool writeCamData();
    bool writeGpsData();

    DataContext *m_context;
    rosbag::Bag m_bag;

    bool m_cam_flag;
    bool m_gps_flag;

    cv::Mat m_img_frame;
    // A Position Member
};
}
#endif // DATA_COMBINER_HPP_
