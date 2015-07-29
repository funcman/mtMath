#ifndef MTVEC2_H
#define MTVEC2_H

#include <string>

class mtVec2 {
public:
    float x;
    float y;
public:
                mtVec2();
    explicit    mtVec2(float x, float y);
                mtVec2(mtVec2 const& vec);

    mtVec2&     operator=(mtVec2 const& vec);
    mtVec2      operator+(mtVec2 const& vec)    const;
    mtVec2      operator-(mtVec2 const& vec)    const;
    mtVec2      operator*(float scalar)         const;
    mtVec2      operator/(float scalar)         const;
    mtVec2      operator-()                     const;

    float       len()                           const;
    float       squaredLen()                    const;
    float       normalize(float epsilon);

    std::string toString();
};

#include "mtVec2.inl"

#endif//MTVEC2_H

