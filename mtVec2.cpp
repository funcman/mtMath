#include "mtVec2.h"
#include <sstream>

std::string mtVec2::toString() {
    std::ostringstream stream;
    stream << "(" << x << ", " << y << ")";
    return stream.str();
}
