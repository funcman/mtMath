#include "mtPt3.h"
#include <sstream>

std::string mtPt3::toString() {
    std::ostringstream stream;
    stream << "pt3 (" << x << ", " << y << ", " << z << ")";
    return stream.str();
}
