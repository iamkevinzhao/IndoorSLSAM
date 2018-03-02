#include "map_generator.h"
#include <limits>
#include <cmath>
#include <iostream>
#include "IndoorSLSAM/utility/utilities.h"

using namespace std;

namespace slsam {
MapGenerator::MapGenerator() : resolution_(0.05f), prob_per_point_(0.1) {}
bool MapGenerator::AddCloudToMap(const PointCloud2 &cloud, Map2D &map) {
  if (cloud.empty()) {
    return true;
  }
  if (map.resolution != resolution_) {
    uerror(__FILE__, __LINE__, "Resolution not matched.");
    return false;
  }
  Point2 cloud_map_top_right, cloud_map_bottom_left;
  GetMapBoundary(cloud, cloud_map_top_right, cloud_map_bottom_left);
  // TODO: Consider to remove following check
  if (!IsTopRightBottomLeftValid(cloud_map_top_right, cloud_map_bottom_left)) {
    uerror(__FILE__, __LINE__, "Invalid boundary extraction.");
    return false;
  }
  Point2 original_map_top_right, original_map_bottom_left;
  original_map_bottom_left = map.origin;
  original_map_top_right =
      map.origin + Vector2{map.iw(), map.ih()} * map.resolution;
  Point2 map_top_right, map_bottom_left;
  MergeMapBoundaries(
      original_map_top_right, original_map_bottom_left,
      cloud_map_top_right, cloud_map_bottom_left,
      map_top_right, map_bottom_left);

  int width, height;
  width = ceil(map_top_right.x - map_bottom_left.x) / resolution_;
  height = ceil((map_top_right.y - map_bottom_left.y) / resolution_);
  if (width <= 0 || height <= 0) {
    uerror(__FILE__, __LINE__, "Invalid width or height");
    return false;
  }
  // map.map.resize(width, height);
  map.map.setConstant(width, height, kMapCellProbMin);

  map.resolution = resolution_;
  map.origin = map_bottom_left; // Notice!

  int ix, iy;
  // Add cloud to the map
  for (auto& point : cloud) {
    ix = std::floor((point.x - map.origin.x) / resolution_);
    iy = std::floor((point.y - map.origin.y) / resolution_);
    map.map(ix, iy) += prob_per_point_;
    if (map.map(ix, iy) > kMapCellProbMax) {
      map.map(ix, iy) = kMapCellProbMax;
    }
  }

  // Add original map to the map

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

void MapGenerator::MergeMapBoundaries(
    const Point2 &bound1_top_right, const Point2 &bound1_bottom_left,
    const Point2 &bound2_top_right, const Point2 &bound2_bottom_left,
    Point2& bound_top_right, Point2& bound_bottom_left) {
  bound_top_right.x = std::max(bound1_top_right.x, bound2_top_right.x);
  bound_top_right.y = std::max(bound1_top_right.y, bound2_top_right.y);
  bound_bottom_left.x = std::min(bound1_bottom_left.x, bound2_bottom_left.x);
  bound_bottom_left.y = std::min(bound1_bottom_left.y, bound2_bottom_left.y);
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
