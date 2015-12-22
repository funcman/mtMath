#include "mtMat44.h"
#include <sstream>
#include <iomanip>

std::string mtMat44::toString() const {
    std::ostringstream stream;
    stream << "mat44" << std::endl;
    for (int i=0; i<4; ++i) {
        stream << "| ";
        for (int j=0; j<4; ++j) {
            stream << std::setiosflags(std::ios::fixed) << std::setprecision(3) << std::setw(18) << std::right;
            stream << m[i][j];
            if (j < 3) {
                stream << ", ";
            }
        }
        stream << " |" << std::endl;
    }
    return stream.str();
}
