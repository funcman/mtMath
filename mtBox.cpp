#include "mtBox.h"
#include <sstream>

mtBox mtBox::leftHand() const {
    float bx, by, bz;
    float lx, ly, lz;
    if (p1.x < p2.x) {
        bx = p1.x;
        lx = p2.x;
    }else {
        bx = p2.x;
        lx = p1.x;
    }
    if (p1.y < p2.y) {
        by = p1.y;
        ly = p2.y;
    }else {
        by = p2.y;
        ly = p1.y;
    }
    if (p1.z < p2.z) {
        bz = p1.z;
        lz = p2.z;
    }else {
        bz = p2.z;
        lz = p1.z;
    }
    return mtBox(mtPt3(bx,by,bz), mtPt3(lx,ly,lz));
}

mtBox mtBox::rightHand() const {
    float bx, by, bz;
    float lx, ly, lz;
    if (p1.x > p2.x) {
        bx = p1.x;
        lx = p2.x;
    }else {
        bx = p2.x;
        lx = p1.x;
    }
    if (p1.y > p2.y) {
        by = p1.y;
        ly = p2.y;
    }else {
        by = p2.y;
        ly = p1.y;
    }
    if (p1.z > p2.z) {
        bz = p1.z;
        lz = p2.z;
    }else {
        bz = p2.z;
        lz = p1.z;
    }
    return mtBox(mtPt3(bx, by, bz), mtPt3(lx, ly, lz));
}

std::string mtBox::toString() const {
    std::ostringstream stream;
    stream << "box [(" << p1.x << "," << p1.y << "," << p1.z << ") - (" << p2.x << "," << p2.y << "," << p2.z << ")]";
    return stream.str();
}
