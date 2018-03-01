#ifndef INDOORSLSAM_GEOMETRY_MAP2D_H_
#define INDOORSLSAM_GEOMETRY_MAP2D_H_

#include <Eigen/Dense>

namespace slsam {
using MapMatrix = Eigen::MatrixXf;
struct Map2D {
  /**
   * @brief map.rows() returns the width of the map
   *        map.cols() return the height of the map
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
};
}

#endif // INDOORSLSAM_GEOMETRY_MAP2D_H_
