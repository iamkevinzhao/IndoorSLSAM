#ifndef INDOORSLSAM_PERCEPTION_POINT_CLOUD2_H
#define INDOORSLSAM_PERCEPTION_POINT_CLOUD2_H

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include "IndoorSLSAM/utility/utilities.h"

namespace slsam {
using Point2 = pcl::PointXY;
using PointCloud2 = pcl::PointCloud<Point2>;

void set_min(Point2& point);
void set_max(Point2& point);

inline Point2 operator+(const Point2& p, const Vector2& v) {
  return Point2{p.x + v(0), p.y + v(1)};
}
} // namespace slsam

#endif // INDOORSLSAM_PERCEPTION_POINT_CLOUD2_H
