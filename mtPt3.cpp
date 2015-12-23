#include "mtPt3.h"
#include <sstream>
#include "mtBox.h"

mtBox mtPt3::operator*(mtPt3 const& pt) const {
    return mtBox(*this, pt).leftHand();
}

std::string mtPt3::toString() const {
    std::ostringstream stream;
    stream << "pt3 (" << x << ", " << y << ", " << z << ")";
    return stream.str();
}
