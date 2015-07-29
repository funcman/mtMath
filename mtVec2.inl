#include <float.h>
#include <math.h>

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

inline mtVec2& mtVec2::operator=(mtVec2 const& vec) {
    x = vec.x;
    y = vec.y;
    return *this;
}

inline mtVec2 mtVec2::operator+(mtVec2 const& vec) const {
    return mtVec2(x+vec.x, y+vec.y);
}

inline mtVec2 mtVec2::operator-(mtVec2 const& vec) const {
    return mtVec2(x-vec.x, y-vec.y);
}

inline mtVec2 mtVec2::operator*(float scalar) const {
    return mtVec2(x*scalar, y*scalar);
}

inline mtVec2 mtVec2::operator/(float scalar) const {
    if (scalar != 0.f) {
        return mtVec2(x/scalar, y/scalar);
    }
    return mtVec2(FLT_MAX, FLT_MAX);
}

inline mtVec2 mtVec2::operator-() const {
    return mtVec2(-x, -y);
}

inline float mtVec2::len() const {
    float sqrlen = x * x + y * y;
    return sqrtf(sqrlen);
}

inline float mtVec2::squaredLen() const {
    return x * x + y * y;
}

inline float mtVec2::normalize(float epsilon) {
    float len = this->len();
    if (len > epsilon) {
        float invlen = 1.f / len;
        x *= invlen;
        y *= invlen;
    }else {
        len = 0.f;
        x   = 0.f;
        y   = 0.f;
    }
    return len;
}

