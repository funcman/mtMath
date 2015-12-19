#ifndef MTPT3_H
#define MTPT3_H

#include <string>

class mtVec3;

class mtPt3 {
public:
    float x;
    float y;
    float z;
public:
    mtPt3();
    explicit    mtPt3(float x, float y, float z);
    mtPt3(mtPt3 const& pt);

    mtPt3&      operator=(mtPt3 const& pt);
    mtPt3       operator+(mtPt3 const& pt)                      const;
    mtPt3       operator-(mtPt3 const& pt)                      const;
    mtPt3       operator-()                                     const;
    bool        operator==(mtPt3 const& pt)                     const;
    bool        operator!=(mtPt3 const& pt)                     const;

    mtPt3       operator+(mtVec3 const& vec)                    const;
    mtPt3       operator-(mtVec3 const& vec)                    const;
//    mtCube      operator*(mtPt3 const& vec)                     const;

    std::string toString();
};

#include "mtPt3.inl"

#endif//MTPT3_H
