#ifndef MTVEC3_H
#define MTVEC3_H

#include <string>
#include "mtCommon.h"

class mtPt3;
class mtMat44;

class mtVec3 {
public:
    float x;
    float y;
    float z;
public:
                mtVec3();
    explicit    mtVec3(float x, float y, float z);
                mtVec3(mtVec3 const& vec);

    mtVec3&     operator=(mtVec3 const& vec);
    mtVec3      operator+(mtVec3 const& vec)                    const;
    mtVec3      operator-(mtVec3 const& vec)                    const;
    float       operator*(mtVec3 const& vec)                    const;
    mtVec3      operator*(mtMat44 const& mat)                   const;
    mtVec3      operator*(float scalar)                         const;
    mtVec3      operator/(float scalar)                         const;
    mtVec3      operator-()                                     const;
    bool        operator==(mtVec3 const& vec)                   const;
    bool        operator!=(mtVec3 const& vec)                   const;

    mtPt3       operator+(mtPt3 const& pt)                      const;
    mtPt3       operator-(mtPt3 const& pt)                      const;

    float       dot(mtVec3 const& vec)                          const;
    mtVec3      cross(mtVec3 const& vec)                        const;
    float       norm()                                          const;
    float       squaredNorm()                                   const;
    float       normalize(float epsilon=0.f);
    mtVec3      interpolate(mtVec3 const& vec, float factor)    const;
    mtVec3      transform(mtMat44 const& mat)                   const;

    std::string toString()                                      const;
};

#include "mtVec3.inl"

#endif//MTVEC3_H
