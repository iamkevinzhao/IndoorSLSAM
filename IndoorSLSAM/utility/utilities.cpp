#include "utilities.h"
#include <iostream>

using namespace std;

namespace slsam {
void uerror(const std::string &file, const int &line, const std::string &msg) {
  cerr <<
      "Error (" << "file: " << file << ", line: " << line << "): " <<
      msg << endl;
}
}
