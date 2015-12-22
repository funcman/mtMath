#include "mtPt2.h"

inline mtRect::mtRect() {
    leftTop     = mtPt2();
    rightBottom = mtPt2();
}

inline mtRect::mtRect(mtPt2 const& leftTop, mtPt2 const& rightBottom) {
    this->leftTop       = leftTop;
    this->rightBottom   = rightBottom;
}

inline mtRect::mtRect(mtRect const& rect) {
    leftTop     = rect.leftTop;
    rightBottom = rect.rightBottom;
}

inline mtRect& mtRect::operator=(mtRect const& rect) {
    leftTop     = rect.leftTop;
    rightBottom = rect.rightBottom;
    return *this;
}

inline bool mtRect::operator==(mtRect const& rect) const {
    mtRect r1 = this->leftHand();
    mtRect r2 = rect.leftHand();
    return r1.leftTop==r2.leftTop && r1.rightBottom==r2.rightBottom;
}

inline bool mtRect::operator!=(mtRect const& rect) const {
    mtRect r1 = this->leftHand();
    mtRect r2 = rect.leftHand();
    return r1.leftTop!=r2.leftTop || r1.rightBottom!=r2.rightBottom;
}

inline mtRect mtRect::operator+(mtVec2 const& vec) const {
    return mtRect(leftTop+vec, rightBottom+vec);
}

inline mtRect mtRect::operator-(mtVec2 const& vec) const {
    return mtRect(leftTop-vec, rightBottom-vec);
}
