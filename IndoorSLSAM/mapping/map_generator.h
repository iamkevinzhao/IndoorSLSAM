#ifndef INDOOR_SLSAM_MAPPING_MAP_GENERATOR_H_
#define INDOOR_SLSAM_MAPPING_MAP_GENERATOR_H_

#include "IndoorSLSAM/perception/point_cloud2.h"
#include "map2d.h"

namespace slsam {
class MapGenerator {
 public:
  MapGenerator();
  void SetResolution(const float& resolution) {
    resolution_ = resolution;
  }
  void AddCloudToMap(const PointCloud2& cloud, Map2D& map);
 private:
  float resolution_;
};
} // namespace slsam

#endif // INDOOR_SLSAM_MAPPING_MAP_GENERATOR_H_
