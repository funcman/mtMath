#include <float.h>
#include <math.h>

inline mtVec3::mtVec3() {
    x = 0.f;
    y = 0.f;
    x = 0.f;
}

inline mtVec3::mtVec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

inline mtVec3::mtVec3(mtVec3 const& vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

inline mtVec3& mtVec3::operator=(mtVec3 const& vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    return *this;
}

inline mtVec3 mtVec3::operator+(mtVec3 const& vec) const {
    return mtVec3(x+vec.x, y+vec.y, z+vec.z);
}

inline mtVec3 mtVec3::operator-(mtVec3 const& vec) const {
    return mtVec3(x-vec.x, y-vec.y, z-vec.z);
}

inline mtVec3 mtVec3::operator*(float scalar) const {
    return mtVec3(x*scalar, y*scalar, z*scalar);
}

inline mtVec3 mtVec3::operator/(float scalar) const {
    if (scalar != 0.f) {
        return mtVec3(x/scalar, y/scalar, z/scalar);
    }
    return mtVec3(FLT_MAX, FLT_MAX, FLT_MAX);
}

inline mtVec3 mtVec3::operator-() const {
    return mtVec3(-x, -y, -z);
}

inline bool mtVec3::operator==(mtVec3 const& vec) const {
    return floatEqual(x, vec.x) && floatEqual(y, vec.y) && floatEqual(z, vec.z);
}

inline bool mtVec3::operator!=(mtVec3 const& vec) const {
    return (!floatEqual(x, vec.x)) || (!floatEqual(y, vec.y)) || (!floatEqual(z, vec.z));
}

inline float mtVec3::len() const {
    float sqrlen = x * x + y * y + z * z;
    return sqrtf(sqrlen);
}

inline float mtVec3::squaredLen() const {
    return x * x + y * y + z * z;
}

inline float mtVec3::normalize(float epsilon) {
    float len = this->len();
    if (len > epsilon) {
        float invlen = 1.f / len;
        x *= invlen;
        y *= invlen;
        z *= invlen;
    }else {
        len = 0.f;
        x   = 0.f;
        y   = 0.f;
        z   = 0.f;
    }
    return len;
}

inline mtVec3 mtVec3::interpolate(mtVec3 const& vec, float factor) const {
    return *this + (vec - *this) * factor;
}

inline float mtVec3::dot(mtVec3 const& vec) const {
    return x * vec.x + y * vec.y + z * vec.z;
}

inline mtVec3 mtVec3::cross(mtVec3 const& vec) const {
    return mtVec3(y*vec.z-z*vec.y, z*vec.x-x*vec.z, x*vec.y-y*vec.x);
}
