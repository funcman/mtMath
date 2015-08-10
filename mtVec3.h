#ifndef MTVEC3_H
#define MTVEC3_H

#include <string>
#include "mtCommon.h"

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
    mtVec3      operator*(float scalar)                         const;
    mtVec3      operator/(float scalar)                         const;
    mtVec3      operator-()                                     const;
    bool        operator==(mtVec3 const& vec)                   const;
    bool        operator!=(mtVec3 const& vec)                   const;

    float       len()                                           const;
    float       squaredLen()                                    const;
    float       normalize(float epsilon=0.f);
    mtVec3      interpolate(mtVec3 const& vec, float factor)    const;

    float       dot(mtVec3 const& vec)                          const;
    mtVec3      cross(mtVec3 const& vec)                        const;

    std::string toString();
};

#include "mtVec3.inl"

#endif//MTVEC3_H
