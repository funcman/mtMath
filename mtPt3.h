#ifndef MTPT3_H
#define MTPT3_H

#include <string>

class mtVec3;
class mtBox;

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
    mtVec3      from(mtPt3 const& pt)                           const;
    mtVec3      to(mtPt3 const& pt)                             const;
    float       distanceFrom(mtPt3 const& pt)                   const;
    float       distanceTo(mtPt3 const& pt)                     const;

    mtBox       operator*(mtPt3 const& pt)                      const;

    std::string toString()                                      const;
};

#include "mtPt3.inl"

#endif//MTPT3_H
