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

    std::string toString();
};

#include "mtVec2.inl"

#endif//MTVEC2_H

