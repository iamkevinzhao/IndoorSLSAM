#pragma once
#ifndef INDOORSLSAM_SLSAM_H
#define INDOORSLSAM_SLSAM_H

#include <IndoorSLSAM/config.h>
#include "sensor/scan2d.h"
#include <memory>

namespace slsam {
class Slsam {
 public:
  void AddScan(std::shared_ptr<Scan2D> scan);
};
} // namespace slsam

#endif
