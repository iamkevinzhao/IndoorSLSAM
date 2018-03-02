#include "map_generator.h"
#include <limits>
#include <cmath>

using namespace std;

namespace slsam {
MapGenerator::MapGenerator() : resolution_(0.5f) {}
bool MapGenerator::AddCloudToMap(const PointCloud2 &cloud, Map2D &map) {
  if (cloud.empty()) {
    return false;
  }
  Point2 top_right, bottom_left;
  GetMapBoundary(cloud, top_right, bottom_left);
  if (!IsTopRightBottomLeftValid(top_right, bottom_left)) {
    return false;
  }
  float width, height;
  width = ceil(top_right.x - bottom_left.x) / resolution_;
  height = ceil((top_right.y - bottom_left.y) / resolution_);
  map.map.resize(width, height);

  // For testing
  for (int w = 0; w < map.iw(); ++w) {
    for (int h = 0; h < map.ih(); ++h) {
      map.map(w, h) = 0.5;
    }
  }
  map.resolution = resolution_;
  map.origin = bottom_left;
  return true;
}

void MapGenerator::GetMapBoundary(
    const PointCloud2 &cloud, Point2 &top_right, Point2 &bottom_left) {
  set_min(top_right);
  set_max(bottom_left);
  for (auto& point : cloud) {
    if (point.x > top_right.x) {
      top_right.x = point.x;
    }
    if (point.y > top_right.y) {
      top_right.y = point.y;
    }
    if (point.x < bottom_left.x) {
      bottom_left.x = point.x;
    }
    if (point.y < bottom_left.y) {
      bottom_left.y = point.y;
    }
  }
}

bool MapGenerator::IsTopRightBottomLeftValid(
    const Point2 &top_right, const Point2 &bottom_left) {
  if (top_right.x < bottom_left.x) {
    return false;
  }
  if (top_right.y < bottom_left.y) {
    return false;
  }
  return true;
}
} // namespace slsam
