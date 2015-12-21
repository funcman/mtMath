#include "mtVec3.h"

inline mtPt3::mtPt3() {
    x = 0;
    y = 0;
    z = 0;
}

inline mtPt3::mtPt3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

inline mtPt3::mtPt3(mtPt3 const& pt) {
    x = pt.x;
    y = pt.y;
    z = pt.z;
}

inline mtPt3& mtPt3::operator=(mtPt3 const& pt) {
    x = pt.x;
    y = pt.y;
    z = pt.z;
    return *this;
}

inline mtPt3 mtPt3::operator+(mtPt3 const& pt) const {
    return mtPt3(x+pt.x, y+pt.y, z+pt.z);
}

inline mtPt3 mtPt3::operator-(mtPt3 const& pt) const {
    return mtPt3(x-pt.x, y-pt.y, z-pt.z);
}

inline mtPt3 mtPt3::operator-() const {
    return mtPt3(-x, -y, -z);
}

inline bool mtPt3::operator==(mtPt3 const& pt) const {
    return x==pt.x && y==pt.y && z==pt.z;
}

inline bool mtPt3::operator!=(mtPt3 const& pt) const {
    return x!=pt.x || y!=pt.y || z!=pt.z;
}

inline mtPt3 mtPt3::operator+(mtVec3 const& vec) const {
    return mtPt3(x+vec.x, y+vec.y, z+vec.z);
}

inline mtPt3 mtPt3::operator-(mtVec3 const& vec) const {
    return mtPt3(x-vec.x, y-vec.y, z-vec.z);
}

inline mtVec3 mtPt3::from(mtPt3 const& pt) const {
    return mtVec3(x-pt.x, y-pt.y, z-pt.z);
}

inline mtVec3 mtPt3::to(mtPt3 const& pt) const {
    return mtVec3(pt.x-x, pt.y-y, pt.z-z);
}
