#ifndef MTVEC2_H
#define MTVEC2_H

#include <string>
#include "mtCommon.h"

class mtPt2;

class mtVec2 {
public:
    float x;
    float y;
public:
                mtVec2();
    explicit    mtVec2(float x, float y);
                mtVec2(mtVec2 const& vec);

    mtVec2&     operator=(mtVec2 const& vec);
    mtVec2      operator+(mtVec2 const& vec)                    const;
    mtVec2      operator-(mtVec2 const& vec)                    const;
    mtVec2      operator*(float scalar)                         const;
    mtVec2      operator/(float scalar)                         const;
    mtVec2      operator-()                                     const;
    bool        operator==(mtVec2 const& vec)                   const;
    bool        operator!=(mtVec2 const& vec)                   const;

    mtPt2       operator+(mtPt2 const& pt)                      const;
    mtPt2       operator-(mtPt2 const& pt)                      const;

    float       len()                                           const;
    float       squaredLen()                                    const;
    float       normalize(float epsilon=MTMATH_FLOAT_EPSILON);
    mtVec2      interpolate(mtVec2 const& vec, float factor)    const;

    std::string toString()                                      const;
};

#include "mtVec2.inl"

#endif//MTVEC2_H
