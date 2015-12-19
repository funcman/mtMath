#include "mtVec2.h"

inline mtPt2::mtPt2() {
    x = 0;
    y = 0;
}

inline mtPt2::mtPt2(float x, float y) {
    this->x = x;
    this->y = y;
}

inline mtPt2::mtPt2(mtPt2 const& pt) {
    x = pt.x;
    y = pt.y;
}

inline mtPt2& mtPt2::operator=(mtPt2 const& pt) {
    x = pt.x;
    y = pt.y;
    return *this;
}

inline mtPt2 mtPt2::operator+(mtPt2 const& pt) const {
    return mtPt2(x+pt.x, y+pt.y);
}

inline mtPt2 mtPt2::operator-(mtPt2 const& pt) const {
    return mtPt2(x-pt.x, y-pt.y);
}

inline mtPt2 mtPt2::operator-() const {
    return mtPt2(-x, -y);
}

inline bool mtPt2::operator==(mtPt2 const& pt) const {
    return x==pt.x && y==pt.y;
}

inline bool mtPt2::operator!=(mtPt2 const& pt) const {
    return x!=pt.x || y!=pt.y;
}

inline mtPt2 mtPt2::operator+(mtVec2 const& vec) const {
    return mtPt2(x+vec.x, y+vec.y);
}

inline mtPt2 mtPt2::operator-(mtVec2 const& vec) const {
    return mtPt2(x-vec.x, y-vec.y);
}