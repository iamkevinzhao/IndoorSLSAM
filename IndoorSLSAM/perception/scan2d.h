#ifndef INDOORSLSAM_PERCEPTION_SCAN2D_H_
#define INDOORSLSAM_PERCEPTION_SCAN2D_H_

#include <vector>
#include "point_cloud2.h"
#include "IndoorSLSAM/utility/time.h"

namespace slsam {
/**
 * @brief 2D Laser Scan
 * For specifications, Scan2D align with ROS sensor_msgs::LaserScan
   *            y
   *            ^
   *            |   *
   *            |  .|
   *            | . |
   *            |.@ |
   *  ---------------------->x
   *            |
   *            |
   *            |
   *            |
   * "...": the beam channel of the scan
   * "@": the angle (in radius) of the beam.
   *      When angle is 0, the beam is on the X axis.
   *      When angle is Pi/2, the beam is on the Y axis.
   * "*": the end point of the beam
 */
struct Scan2D {
  Time stamp;
  float angle_min; // start angle of the scan [rad]
  float angle_max; // end angle of the scan [rad]
  float angle_increment; // angular distance between measurements [rad]

  float time_increment; // time between measurements [seconds]
  float scan_time; // time between scans [seconds]

  float range_min; // minimum range value [m]
  float range_max; // maximum range value [m]

  std::vector<float> ranges; // range data [m]
  std::vector<float> intensities; // intensity data
};
} // namespace slsam

#endif // INDOORSLSAM_PERCEPTION_SCAN2D_H_
