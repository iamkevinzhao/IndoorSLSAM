#ifndef INDOORSLSAM_GEOMETRY_MAP2D_H_
#define INDOORSLSAM_GEOMETRY_MAP2D_H_

#include <Eigen/Dense>

namespace slsam {
using MapMatrix = Eigen::MatrixXf;
struct Map2D {
  MapMatrix map;
  int iw() const;
  int ih() const;
};
}

#endif // INDOORSLSAM_GEOMETRY_MAP2D_H_
