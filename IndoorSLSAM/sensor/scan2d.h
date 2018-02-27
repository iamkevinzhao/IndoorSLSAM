#ifndef INDOORSLSAM_SENSOR_SCAN2D_H_
#define INDOORSLSAM_SENSOR_SCAN2D_H_

#include <vector>
 #include <pcl/point_cloud.h>
 #include <pcl/point_types.h>

namespace slsam {
using Point2D = pcl::PointXY;
struct Scan2D {
  pcl::PointCloud<Point2D> points;
};
} // namespace slsam

#endif // INDOORSLSAM_SENSOR_SCAN2D_H_
