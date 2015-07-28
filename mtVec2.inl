inline mtVec2::mtVec2() {
    x = 0;
    y = 0;
}

inline mtVec2::mtVec2(float x, float y) {
    this->x = x;
    this->y = y;
}

inline mtVec2::mtVec2(mtVec2 const& vec) {
    x = vec.x;
    y = vec.y;
}

