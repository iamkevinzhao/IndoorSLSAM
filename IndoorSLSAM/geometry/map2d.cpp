#include "map2d.h"

namespace slsam {
int Map2D::ih() const {
  return map.cols();
}

int Map2D::iw() const {
  return map.rows();
}
}
