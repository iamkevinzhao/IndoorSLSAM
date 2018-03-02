#ifndef INDOOR_SLSAM_MAPPING_MAP_GENERATOR_H_
#define INDOOR_SLSAM_MAPPING_MAP_GENERATOR_H_

#include "IndoorSLSAM/perception/point_cloud2.h"
#include "map2d.h"

namespace slsam {
class MapGenerator {
 public:
  MapGenerator();
  inline void SetResolution(const float& resolution) {
    resolution_ = resolution;
  }
  bool AddCloudToMap(const PointCloud2& cloud, Map2D& map);
 private:
  /**
   * @brief GetMapBoundary
   *            y
   *            ^
   *            |
   *            |
   *       *****|****+
   *       *****|*****
   *  ---------------------->x
   *       -****|*****
   *            |
   *            |
   *            |
   * @param cloud The point cloud
   * @param top_right Cartesian coordinate of the top-right corner
   *        (denoted as "+" above)
   * @param bottom_left Cartesian coordinate of the bottom-down corner
   *        (denoted as "-" above)
   */
  static void GetMapBoundary(
      const PointCloud2& cloud, Point2& top_right, Point2& bottom_left);
  static bool IsTopRightBottomLeftValid(
      const Point2& top_right, const Point2& bottom_left);
  static void MergeMapBoundaries(
      const Point2& bound1_top_right, const Point2& bound1_bottom_left,
      const Point2& bound2_top_right, const Point2& bound2_bottom_left,
      Point2& bound_top_right, Point2& bound_bottom_left);
  float resolution_;
  float prob_per_point_;
};
} // namespace slsam

#endif // INDOOR_SLSAM_MAPPING_MAP_GENERATOR_H_
