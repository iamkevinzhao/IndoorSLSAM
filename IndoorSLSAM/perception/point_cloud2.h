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

inline Vector2 operator-(const Point2& p1, const Point2& p2) {
  return Vector2{p1.x - p2.x, p1.y - p2.y};
}

inline Point2 operator-(const Point2& p1, const Vector2& vec) {
  return Point2{p1.x - vec(0), p1.y - vec(1)};
}

inline Vector2 ceil(const Vector2& vec) {
  return Vector2{std::ceil(vec(0)), std::ceil(vec(1))};
}
} // namespace slsam

#endif // INDOORSLSAM_PERCEPTION_POINT_CLOUD2_H
