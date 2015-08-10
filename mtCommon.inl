#include <math.h>

inline bool floatEqual(float a, float b) {
    return fabsf(a - b) <= MTMATH_FLOAT_EPSILON;
}

inline float degrees2Radians(float degrees) {
    return MTMATH_PI * degrees / 180.f;
}

inline float radians2Degrees(float radians) {
    return 180.f * radians / MTMATH_PI;
}
