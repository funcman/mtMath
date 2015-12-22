#include "mtRect.h"
#include <sstream>

mtRect mtRect::leftHand() const {
    float ltx, lty;
    float rbx, rby;
    if (leftTop.x < rightBottom.x) {
        ltx = leftTop.x;
        rbx = rightBottom.x;
    }else {
        ltx = rightBottom.x;
        rbx = leftTop.x;
    }
    if (leftTop.y < rightBottom.y) {
        lty = leftTop.y;
        rby = rightBottom.y;
    }else {
        lty = rightBottom.y;
        rby = leftTop.y;
    }
    return mtRect(mtPt2(ltx,lty), mtPt2(rbx,rby));
}

mtRect mtRect::rightHand() const {
    float ltx, lty;
    float rbx, rby;
    if (leftTop.x > rightBottom.x) {
        ltx = leftTop.x;
        rbx = rightBottom.x;
    }else {
        ltx = rightBottom.x;
        rbx = leftTop.x;
    }
    if (leftTop.y < rightBottom.y) {
        lty = leftTop.y;
        rby = rightBottom.y;
    }else {
        lty = rightBottom.y;
        rby = leftTop.y;
    }
    return mtRect(mtPt2(ltx,lty), mtPt2(rbx,rby));
}

std::string mtRect::toString() const {
    std::ostringstream stream;
    stream << "rect [(" << leftTop.x << "," << leftTop.y << ") - (" << rightBottom.x << "," << rightBottom.y << ")]";
    return stream.str();
}
