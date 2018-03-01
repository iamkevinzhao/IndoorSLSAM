#include "slsam.h"
#include <iostream>
#include <Eigen/Dense>

using namespace std;

namespace slsam {
void Slsam::AddScan(std::shared_ptr<Scan2D> scan) {
  scan_ = scan;
}

std::shared_ptr<Map2D> Slsam::GenerateMap() {
  shared_ptr<Map2D> map(new Map2D);
  int width = 10, height = 20;
  map->map.resize(width, height);
  for (int w = 0; w < width; ++w) {
    for (int h = 0; h < height; ++h) {
      map->map(w, h) = 0.5f;
    }
  }
  return map;
}
} // namespace slsam
