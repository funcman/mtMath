#ifndef MTVEC3_H
#define MTVEC3_H

#include <string>

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
    mtVec3      operator+(mtVec3 const& vec)    const;
    mtVec3      operator-(mtVec3 const& vec)    const;
    mtVec3      operator*(float scalar)         const;
    mtVec3      operator/(float scalar)         const;
    mtVec3      operator-()                     const;

    float       len()                           const;
    float       squaredLen()                    const;
    float       normalize(float epsilon);

    float       dot(mtVec3 const& vec)          const;
    mtVec3      cross(mtVec3 const& vec)        const;

    std::string toString();
};

#include "mtVec3.inl"

#endif//MTVEC3_H

