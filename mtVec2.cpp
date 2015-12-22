#include "mtVec2.h"
#include <sstream>

std::string mtVec2::toString() const {
    std::ostringstream stream;
    stream << "vec2 (" << x << ", " << y << ")";
    return stream.str();
}
