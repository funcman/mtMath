#include "mtVec3.h"
#include <sstream>

std::string mtVec3::toString() const {
    std::ostringstream stream;
    stream << "vec3 (" << x << ", " << y << ", "<< z << ")";
    return stream.str();
}
