inline mtBox::mtBox() {
    p1 = mtPt3();
    p2 = mtPt3();
}

inline mtBox::mtBox(mtPt3 const& pt1, mtPt3 const& pt2) {
    p1 = pt1;
    p2 = pt2;
}

inline mtBox::mtBox(mtBox const& box) {
    p1 = box.p1;
    p2 = box.p2;
}

inline mtBox& mtBox::operator=(mtBox const& box) {
    p1 = box.p1;
    p2 = box.p2;
    return *this;
}

inline bool mtBox::operator==(mtBox const& box) const {
    mtBox b1 = this->leftHand();
    mtBox b2 = box.leftHand();
    return b1.p1==b2.p1 && b1.p2==b2.p2;
}

inline bool mtBox::operator!=(mtBox const& box) const {
    mtBox b1 = this->leftHand();
    mtBox b2 = box.leftHand();
    return b1.p1!=b2.p1 || b1.p2!=b2.p2;
}

inline mtBox mtBox::operator+(mtVec3 const& vec) const {
    return mtBox(p1+vec, p2+vec);
}

inline mtBox mtBox::operator-(mtVec3 const& vec) const {
    return mtBox(p1-vec, p2-vec);
}
