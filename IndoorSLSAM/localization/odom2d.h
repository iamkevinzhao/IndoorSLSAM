#ifndef INDOORSLSAM_LOCALIZATION_ODOM2D_H_
#define INDOORSLSAM_LOCALIZATION_ODOM2D_H_

#include "IndoorSLSAM/utility/time.h"
#include "IndoorSLSAM/utility/transform.h"
#include "IndoorSLSAM/utility/utilities.h"

namespace slsam {
struct Odom2D {
  Time stamp;
  Translation2 position;
  Matrix2 position_covariance;
  Rotation2 heading;
  float heading_covariance;
};
} // namespace slsam

#endif // INDOORSLSAM_LOCALIZATION_ODOM2D_H_
