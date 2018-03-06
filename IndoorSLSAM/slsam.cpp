#include "slsam.h"
#include <iostream>
#include <Eigen/Dense>
#include "perception/scan_processor.h"

using namespace std;

namespace slsam {
bool Slsam::Init() {
  map_generator_.reset(new MapGenerator);
}

void Slsam::AddScan(std::shared_ptr<Scan2D> scan) {
  scan_ = scan;
}

std::shared_ptr<Map2D> Slsam::GenerateMap() {
  if (!scan_) {
    return std::shared_ptr<Map2D>();
  }
  static shared_ptr<Map2D> map(new Map2D);
  map->resolution = 0.05f;
  auto cloud = ScanProcessor::Scan2ToCloud2(*scan_);
  if (!cloud) {
    return std::shared_ptr<Map2D>();
  }
  if (!map_generator_->AddCloudToMap(*cloud, *map)) {
    return std::shared_ptr<Map2D>();
  }
  return map;
}
} // namespace slsam
