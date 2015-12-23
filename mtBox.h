#ifndef MTBOX_H
#define MTBOX_H

#include <string>
#include "mtPt3.h"

class mtVec3;

class mtBox {
public:
    mtPt3 p1;
    mtPt3 p2;

public:
                mtBox();
    explicit    mtBox(mtPt3 const& pt1, mtPt3 const& pt2);
                mtBox(mtBox const& box);

    mtBox&      operator=(mtBox const& box);
    bool        operator==(mtBox const& box)                    const;
    bool        operator!=(mtBox const& box)                    const;

    mtBox       operator+(mtVec3 const& vec)                    const;
    mtBox       operator-(mtVec3 const& vec)                    const;

    mtBox       leftHand()                                      const;
    mtBox       rightHand()                                     const;

    std::string toString()                                      const;
};

#include "mtBox.inl"

#endif//MTBOX_H
