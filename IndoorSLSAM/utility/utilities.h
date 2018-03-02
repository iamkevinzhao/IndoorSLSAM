#ifndef INDOORSLSAM_UTILITY_UTILITIES_H
#define INDOORSLSAM_UTILITY_UTILITIES_H

#include <limits>
#include <string>
#include <Eigen/Dense>

namespace slsam {
void uerror(const std::string& file, const int& line, const std::string& msg);

using Vector2 = Eigen::Vector2f;
} // namespace slsam

#endif // INDOORSLSAM_UTILITY_UTILITIES_H
