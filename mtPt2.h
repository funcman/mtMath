#ifndef MTPT2_H
#define MTPT2_H

#include <string>

class mtVec2;

class mtPt2 {
public:
    float x;
    float y;
public:
                mtPt2();
    explicit    mtPt2(float x, float y);
                mtPt2(mtPt2 const& pt);

    mtPt2&      operator=(mtPt2 const& pt);
    mtPt2       operator+(mtPt2 const& pt)                      const;
    mtPt2       operator-(mtPt2 const& pt)                      const;
    mtPt2       operator-()                                     const;
    bool        operator==(mtPt2 const& pt)                     const;
    bool        operator!=(mtPt2 const& pt)                     const;

    mtPt2       operator+(mtVec2 const& vec)                    const;
    mtPt2       operator-(mtVec2 const& vec)                    const;

    std::string toString();
};

#include "mtPt2.inl"

#endif//MTPT2_H
