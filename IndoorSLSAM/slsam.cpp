#include "slsam.h"
#include <iostream>

using namespace std;

namespace slsam {
void Slsam::AddScan(std::shared_ptr<Scan2D> scan) {
  if (!scan) {
    return;
  }
  int sum = 0;
  for (auto& point : scan->points) {
    sum += point.x + point.y;
  }
  cout << sum << endl;
}
} // namespace slsam
