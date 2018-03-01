#pragma once
#ifndef INDOORSLSAM_SLSAM_H
#define INDOORSLSAM_SLSAM_H

#include <IndoorSLSAM/config.h>
#include "perception/scan2d.h"
#include <memory>
#include "mapping/map2d.h"
#include "IndoorSLSAM/mapping/map_generator.h"

namespace slsam {
class Slsam {
 public:
  bool Init();
  void AddScan(std::shared_ptr<Scan2D> scan);
  std::shared_ptr<Map2D> GenerateMap();
 private:
  std::shared_ptr<Scan2D> scan_;
  std::shared_ptr<MapGenerator> map_generator_;
};
} // namespace slsam

#endif
