#include "mtPt2.h"
#include <sstream>
#include "mtRect.h"

mtRect mtPt2::operator*(mtPt2 const& pt) const {
    return mtRect(*this,pt).leftHand();
}

std::string mtPt2::toString() const {
    std::ostringstream stream;
    stream << "pt2 (" << x << ", " << y << ")";
    return stream.str();
}