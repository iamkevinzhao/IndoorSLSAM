#ifndef INDOORSLSAM_GEOMETRY_MAP2D_H_
#define INDOORSLSAM_GEOMETRY_MAP2D_H_

#include <Eigen/Dense>
#include "IndoorSLSAM/perception/point_cloud2.h"

namespace slsam {
using MapMatrix = Eigen::MatrixXf;
struct Map2D {
  /**
   * @brief Map2D constructor
   */
  Map2D();
  /**
   * @brief The underlying map
   *            y
   *            ^
   *            |
   *            |
   *       *****|*****
   *       *****|*****
   *  ---------------------->x
   *       o****|*****
   *            |
   *            |
   *            |
   * The width of the above map is 10
   * The height of the above map is 3
   */
  MapMatrix map;
  /**
   * @brief Index Width
   * @return The number of pixels on width
   */
  inline int iw() const {
    return map.rows();
  }
  /**
   * @brief Index Height
   * @return The number of pixels on height
   */
  int ih() const {
    return map.cols();
  }
  /**
   * @brief The Cartesian coordinate (in meters) of the bottom-left pixel
   *        (as indicated by "o")
   */
  Point2 origin;
  /**
   * @brief The length of each pixel square in meters
   */
  float resolution;
};
}

#endif // INDOORSLSAM_GEOMETRY_MAP2D_H_
