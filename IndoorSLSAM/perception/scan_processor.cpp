#include "scan_processor.h"

using namespace std;

namespace slsam {
shared_ptr<PointCloud2> ScanProcessor::Scan2ToCloud2(const Scan2D &scan) {
  shared_ptr<PointCloud2> cloud(new PointCloud2);
  cloud->reserve(scan.ranges.size());

  float angle_min = scan.angle_min;
  float range_min = scan.range_min;
  float range_max = scan.range_max;
  float angle_increment = scan.angle_increment;

  float angle;
  int i = -1;
  for (auto& range : scan.ranges) {
    ++i;
    if (range > range_max || range < range_min) {
      continue;
    }
    angle = angle_min + angle_increment * i;
    cloud->push_back({range * std::cos(angle), range * std::sin(angle)});
  }
  return cloud;
}
} // namespace slsam
