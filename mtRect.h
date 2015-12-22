#ifndef MTRECT_H
#define MTRECT_H

#include <string>
#include "mtPt2.h"

class mtVec2;

class mtRect {
public:
    mtPt2 leftTop;
    mtPt2 rightBottom;

public:
                mtRect();
    explicit    mtRect(mtPt2 const& leftTop, mtPt2 const& rightBottom);
                mtRect(mtRect const& rect);

    mtRect&     operator=(mtRect const& rect);
    bool        operator==(mtRect const& rect)                  const;
    bool        operator!=(mtRect const& rect)                  const;

    mtRect      operator+(mtVec2 const& vec)                    const;
    mtRect      operator-(mtVec2 const& vec)                    const;

    mtRect      leftHand()                                      const;
    mtRect      rightHand()                                     const;

    std::string toString()                                      const;
};

#include "mtRect.inl"

#endif//MTRECT_H
