#pragma once
#ifndef INDOORSLSAM_SLSAM_H
#define INDOORSLSAM_SLSAM_H

#include <IndoorSLSAM/config.h>
#include "perception/scan2d.h"
#include <memory>
#include "mapping/map2d.h"

namespace slsam {
class Slsam {
 public:
  void AddScan(std::shared_ptr<Scan2D> scan);
  std::shared_ptr<Map2D> GenerateMap();
 private:
  std::shared_ptr<Scan2D> scan_;
};
} // namespace slsam

#endif
