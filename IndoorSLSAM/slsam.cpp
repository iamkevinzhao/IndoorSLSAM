#include "slsam.h"
#include <iostream>
#include <Eigen/Dense>
#include "perception/scan_processor.h"
#include "utility/time.h"

using namespace std;

namespace slsam {
bool Slsam::Init() {
  map_generator_.reset(new MapGenerator);
}

void Slsam::AddScan(std::shared_ptr<Scan2D> scan) {
  scan_ = scan;
}

void Slsam::AddOdom(std::shared_ptr<Odom2D> odom) {
  odom_ = odom;
}

std::shared_ptr<Map2D> Slsam::GenerateMap() {
  if (!scan_) {
    return std::shared_ptr<Map2D>();
  }
  static shared_ptr<Map2D> map(new Map2D);
  if (!map_generator_) {
    return std::shared_ptr<Map2D>();
  }
  map->resolution = map_generator_->GetResolution();
  auto cloud = ScanProcessor::Scan2ToCloud2(*scan_);
  if (!cloud) {
    return std::shared_ptr<Map2D>();
  }
  for (auto& point : *cloud) {
    Translation2 p{point.x, point.y};
    Eigen::Transform<float, 2, 1> trans = odom_->heading * p;
    point.x = trans.translation().x() + odom_->position.x();
    point.y = trans.translation().y() + odom_->position.y();
  }
  if (!map_generator_->AddCloudToMap(*cloud, *map)) {
    return std::shared_ptr<Map2D>();
  }
  return map;
}

bool Slsam::GetPose(Translation2 &translation, Rotation2 &rotation) {
  if (!odom_) {
    return false;
  }
  translation = odom_->position;
  rotation = odom_->heading;
//  translation = Translation2{0.0f, 0.0f};
//  rotation = Rotation2(0.0f);
  return true;
}
} // namespace slsam
