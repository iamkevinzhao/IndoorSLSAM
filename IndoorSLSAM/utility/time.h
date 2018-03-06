#ifndef UTIME_H
#define UTIME_H

#include <chrono>

namespace slsam {
using Time = std::chrono::system_clock::time_point;

inline Time time_now() {
  return std::chrono::system_clock::now();
}

using MSec = std::chrono::microseconds;
using NSec = std::chrono::nanoseconds;
} // namespace slsam

#endif // UTIME_H
