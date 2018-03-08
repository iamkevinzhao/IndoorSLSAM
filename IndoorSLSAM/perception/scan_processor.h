#ifndef INDOOR_SLSAM_PERCEPTION_SCAN_PROCESSOR_H_
#define INDOOR_SLSAM_PERCEPTION_SCAN_PROCESSOR_H_

#include <memory>
#include "point_cloud2.h"
#include "scan2d.h"

namespace slsam {
class ScanProcessor
{
public:
  ScanProcessor();
  /**
   * @brief Convert Scan2D to PointCloud2
   * @param scan The laser scan
   * @return A shared pointer to the generated 2D point cloud
   *         The pointer is guarenteed not null
   */
  static std::shared_ptr<PointCloud2> Scan2ToCloud2(const Scan2D& scan);
};
} // namespace slsam

#endif // INDOOR_SLSAM_PERCEPTION_SCAN_PROCESSOR_H_
