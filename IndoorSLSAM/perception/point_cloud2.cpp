#include "point_cloud2.h"
#include <limits>

using namespace std;

namespace slsam {
void set_min(Point2& point) {
  point.x = numeric_limits<float>::min();
  point.y = numeric_limits<float>::min();
}

void set_max(Point2& point) {
  point.x = numeric_limits<float>::max();
  point.y = numeric_limits<float>::max();
}
} // namespace slsam
