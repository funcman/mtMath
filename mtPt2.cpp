#include "mtPt2.h"
#include <sstream>

std::string mtPt2::toString() {
    std::ostringstream stream;
    stream << "pt2 (" << x << ", " << y << ")";
    return stream.str();
}