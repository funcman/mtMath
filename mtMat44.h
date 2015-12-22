#ifndef MTMAT44_H
#define MTMAT44_H

#include <string>

class mtVec3;

class mtMat44 {
public:
    union {
        struct {
            float m11, m12, m13, m14;
            float m21, m22, m23, m24;
            float m31, m32, m33, m34;
            float m41, m42, m43, m44;
        };
        struct {
            float m[4][4];
        };
    };
public:
                    mtMat44();
                    mtMat44(float* values);
    explicit        mtMat44(
                        float f11, float f12, float f13, float f14,
                        float f21, float f22, float f23, float f24,
                        float f31, float f32, float f33, float f34,
                        float f41, float f42, float f43, float f44
    );
                    mtMat44(mtMat44 const& mat);

    mtMat44&        operator=(mtMat44 const& mat);
                    operator float*();
                    operator float const*()                 const;
    mtMat44         operator+(mtMat44 const& mat)           const;
    mtMat44         operator-(mtMat44 const& mat)           const;
    mtMat44         operator*(mtMat44 const& mat)           const;
    mtMat44         operator*(float scalar)                 const;
    mtMat44         operator/(float scalar)                 const;
    bool            operator==(mtMat44 const& mat)          const;
    bool            operator!=(mtMat44 const& mat)          const;

    static mtMat44  zero();
    static mtMat44  identity();
    static mtMat44  lookAtLH(mtVec3 const& eye, mtVec3 const& target, mtVec3 const& up);
    static mtMat44  lookAtRH(mtVec3 const& eye, mtVec3 const& target, mtVec3 const& up);
    static mtMat44  perspectiveFovLH(float fieldOfView, float aspect, float near, float far);
    static mtMat44  perspectiveFovRH(float fieldOfView, float aspect, float near, float far);

    mtVec3          transform(mtVec3 const& vec)            const;

    std::string     toString()                              const;
};

#include "mtMat44.inl"

#endif//MTMAT44_H
