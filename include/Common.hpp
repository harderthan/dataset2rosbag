#ifndef COMMON_HPP_
#define COMMON_HPP_
namespace dataset2rogbag {
enum DataSetType{
    BEGIN = 0,
    KITTI = 1,
    USER = 2,
    END = 3
};

struct SensorFlags
{
    bool m_cam_flag = false;
    bool m_gps_flag = false;
};
}
#endif // COMMON_HPP_
