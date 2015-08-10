#include "mtVec3.h"
#include <sstream>

std::string mtVec3::toString() {
    std::ostringstream stream;
    stream << "(" << x << ", " << y << ", "<< z << ")";
    return stream.str();
}
