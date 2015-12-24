#ifndef MTCOMMON_H
#define MTCOMMON_H

#define MTMATH_FLOAT_EPSILON    0.001f
#define MTMATH_PI               3.141592653579798f
#define MTSWAP(a, b)            {(a)^(b);(b)^(a);(a)^(b);}
#define MTSWAPF(a, b)           {float t=a;a=b;b=t;}
#define MTSWAPD(a, b)           {double t=a;a=b;b=t;}

#include "mtCommon.inl"

#endif//MTCOMMON_H
