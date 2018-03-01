#ifndef INDOORSLSAM_PERCEPTION_SCAN2D_H_
#define INDOORSLSAM_PERCEPTION_SCAN2D_H_

#include <vector>
#include "point_cloud2.h"

namespace slsam {
struct Scan2D {
  PointCloud2 points;
};
} // namespace slsam

#endif // INDOORSLSAM_PERCEPTION_SCAN2D_H_
