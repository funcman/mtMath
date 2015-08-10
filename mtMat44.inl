#include "mtVec3.h"
#include <math.h>

inline mtMat44::mtMat44() {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            m[i][j] = 0;
        }
    }
}

inline mtMat44::mtMat44(float* values) {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            m[i][j] = values[i*4+j];
        }
    }
}

inline mtMat44::mtMat44(
    float f11, float f12, float f13, float f14,
    float f21, float f22, float f23, float f24,
    float f31, float f32, float f33, float f34,
    float f41, float f42, float f43, float f44
)
:   m11(f11), m12(f12), m13(f13), m14(f14)
,   m21(f21), m22(f22), m23(f23), m24(f24)
,   m31(f31), m32(f32), m33(f33), m34(f34)
,   m41(f41), m42(f42), m43(f43), m44(f44) {
}

inline mtMat44::mtMat44(mtMat44 const& mat)
:   m11(mat.m11), m12(mat.m12), m13(mat.m13), m14(mat.m14)
,   m21(mat.m21), m22(mat.m22), m23(mat.m23), m24(mat.m24)
,   m31(mat.m31), m32(mat.m32), m33(mat.m33), m34(mat.m34)
,   m41(mat.m41), m42(mat.m42), m43(mat.m43), m44(mat.m44) {
}

inline mtMat44& mtMat44::operator=(mtMat44 const& mat) {
    for (int i=0; i<4; ++i) {
        for (int j; j<4; ++j) {
            m[i][j] = mat.m[i][j];
        }
    }
    return *this;
}

inline mtMat44::operator float*() {
    return &m11;
}

inline mtMat44::operator float const*() const {
    return &m11;
}

inline mtMat44 mtMat44::operator+(mtMat44 const& mat) const {
    return mtMat44(
       m11 + mat.m11, m12 + mat.m12, m13 + mat.m13, m14 + mat.m14,
       m21 + mat.m21, m22 + mat.m22, m23 + mat.m23, m24 + mat.m24,
       m31 + mat.m31, m32 + mat.m32, m33 + mat.m33, m34 + mat.m34,
       m41 + mat.m41, m42 + mat.m42, m43 + mat.m43, m44 + mat.m44
    );
}

inline mtMat44 mtMat44::operator-(mtMat44 const& mat) const {
    return mtMat44(
        m11 - mat.m11, m12 - mat.m12, m13 - mat.m13, m14 - mat.m14,
        m21 - mat.m21, m22 - mat.m22, m23 - mat.m23, m24 - mat.m24,
        m31 - mat.m31, m32 - mat.m32, m33 - mat.m33, m34 - mat.m34,
        m41 - mat.m41, m42 - mat.m42, m43 - mat.m43, m44 - mat.m44
    );
}

inline mtMat44 mtMat44::operator*(mtMat44 const& mat) const {
    return mtMat44(
        m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41,
        m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42,
        m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43,
        m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44,
        m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41,
        m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42,
        m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43,
        m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44,
        m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41,
        m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42,
        m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43,
        m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44,
        m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41,
        m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42,
        m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43,
        m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44
    );
}

inline mtMat44 mtMat44::operator*(float scalar) const {
    return mtMat44(
        m11 * scalar, m12 * scalar, m13 * scalar, m14 * scalar,
        m21 * scalar, m22 * scalar, m23 * scalar, m24 * scalar,
        m31 * scalar, m32 * scalar, m33 * scalar, m34 * scalar,
        m41 * scalar, m42 * scalar, m43 * scalar, m44 * scalar
    );
}

inline mtMat44 mtMat44::operator/(float scalar) const {
    if (scalar != 0.f) {
        return mtMat44(
            m11 / scalar, m12 / scalar, m13 / scalar, m14 / scalar,
            m21 / scalar, m22 / scalar, m23 / scalar, m24 / scalar,
            m31 / scalar, m32 / scalar, m33 / scalar, m34 / scalar,
            m41 / scalar, m42 / scalar, m43 / scalar, m44 / scalar
        );
    }
    return mtMat44(
        FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX,
        FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX,
        FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX,
        FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX
    );
}

inline bool mtMat44::operator==(mtMat44 const& mat) const {
    bool equal = true;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            equal = equal && floatEqual(m[i][j], mat.m[i][j]);
        }
    }
    return equal;
}

inline bool mtMat44::operator!=(mtMat44 const& mat) const {
    bool equal = true;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            equal = equal && floatEqual(m[i][j], mat.m[i][j]);
        }
    }
    return !equal;
}

inline mtMat44 mtMat44::identity() {
    return mtMat44(
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    );
}

inline mtMat44 mtMat44::lookAtLH(mtVec3 const& eye, mtVec3 const& target, mtVec3 const& up) {
    mtVec3 axisZ = target - eye;
    mtVec3 axisX = up.cross(axisZ);
    mtVec3 axisY = axisZ.cross(axisX);

    axisX.normalize();
    axisY.normalize();
    axisZ.normalize();

    float eyeX = -axisX.dot(eye);
    float eyeY = -axisY.dot(eye);
    float eyeZ = -axisZ.dot(eye);

    return mtMat44(
        axisX.x, axisY.x, axisZ.x, 0.f,
        axisX.y, axisY.y, axisZ.y, 0.f,
        axisX.z, axisY.z, axisZ.z, 0.f,
        eyeX,    eyeY,    eyeZ,    1.f
    );
}

inline mtMat44 mtMat44::lookAtRH(mtVec3 const& eye, mtVec3 const& target, mtVec3 const& up) {
    mtVec3 axisZ = eye - target;
    mtVec3 axisX = up.cross(axisZ);
    mtVec3 axisY = axisZ.cross(axisX);

    axisX.normalize();
    axisY.normalize();
    axisZ.normalize();

    float eyeX = -axisX.dot(eye);
    float eyeY = -axisY.dot(eye);
    float eyeZ = -axisZ.dot(eye);

    return mtMat44(
        axisX.x, axisY.x, axisZ.x, 0.f,
        axisX.y, axisY.y, axisZ.y, 0.f,
        axisX.z, axisY.z, axisZ.z, 0.f,
        eyeX,    eyeY,    eyeZ,    1.f
    );
}

inline mtMat44 mtMat44::perspectiveFovLH(float fieldOfView, float aspect, float near, float far) {
    float height = 1 / tanf(fieldOfView / 2);
    float width = height / aspect;
    return mtMat44(
        width,  0.f,    0.f,                            0.f,
        0.f,    height, 0.f,                            0.f,
        0.f,    0.f,    far / (far - near),             1.f,
        0.f,    0.f,    (near * far) / (near - far),    0.f
    );
}

inline mtMat44 mtMat44::perspectiveFovRH(float fieldOfView, float aspect, float near, float far) {
    float height = 1 / tanf(fieldOfView / 2);
    float width = height / aspect;
    return mtMat44(
        width,  0.f,    0.f,                            0.f,
        0.f,    height, 0.f,                            0.f,
        0.f,    0.f,    far / (near - far),             1.f,
        0.f,    0.f,    (near * far) / (near - far),    0.f
    );
}

inline mtVec3 mtMat44::transform(mtVec3 const& vec) const {
    float x = vec.x * m[0][0] + vec.y * m[1][0] + vec.z * m[2][0] + m[3][0];
    float y = vec.x * m[0][1] + vec.y * m[1][1] + vec.z * m[2][1] + m[3][1];
    float z = vec.x * m[0][2] + vec.y * m[1][2] + vec.z * m[2][2] + m[3][2];
    float w = vec.x * m[0][3] + vec.y * m[1][3] + vec.z * m[2][3] + m[3][3];
    return mtVec3(x/w, y/w, z/w);
}
