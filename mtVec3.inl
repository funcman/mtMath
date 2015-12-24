#include <float.h>
#include <math.h>
#include "mtPt3.h"
#include "mtMat44.h"

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

inline float mtVec3::operator*(mtVec3 const& vec) const {
    return x * vec.x + y * vec.y + z * vec.z;
}

inline mtVec3 mtVec3::operator*(mtMat44 const& mat) const {
    float x = this->x * mat.m11 + this->y * mat.m21 + this->z * mat.m31 + mat.m41;
    float y = this->x * mat.m12 + this->y * mat.m22 + this->z * mat.m32 + mat.m42;
    float z = this->x * mat.m13 + this->y * mat.m23 + this->z * mat.m33 + mat.m43;
    float w = this->x * mat.m14 + this->y * mat.m24 + this->z * mat.m34 + mat.m44;
    return mtVec3(x / w, y / w, z / w);
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

inline mtPt3 mtVec3::operator+(mtPt3 const& pt) const {
    return mtPt3(pt.x+x, pt.y+y, pt.z+z);
}

inline mtPt3 mtVec3::operator-(mtPt3 const& pt) const {
    return mtPt3(pt.x-x, pt.y-y, pt.z-z);
}

inline float mtVec3::dot(mtVec3 const& vec) const {
    return (*this) *vec;
}

inline mtVec3 mtVec3::cross(mtVec3 const& vec) const {
    return mtVec3(y*vec.z-z*vec.y, z*vec.x-x*vec.z, x*vec.y-y*vec.x);
}

inline float mtVec3::norm() const {
    float sqrlen = x * x + y * y + z * z;
    return sqrtf(sqrlen);
}

inline float mtVec3::squaredNorm() const {
    return x * x + y * y + z * z;
}

inline float mtVec3::normalize(float epsilon) {
    float norm = this->norm();
    if (norm > epsilon) {
        float invlen = 1.f / norm;
        x *= invlen;
        y *= invlen;
        z *= invlen;
    }else {
        norm    = 0.f;
        x       = 0.f;
        y       = 0.f;
        z       = 0.f;
    }
    return norm;
}

inline mtVec3 mtVec3::interpolate(mtVec3 const& vec, float factor) const {
    return *this + (vec - *this) * factor;
}

inline mtVec3 mtVec3::transform(mtMat44 const& mat) const {
    return (*this) * mat;
}
