#pragma once

constexpr auto MATH_TOLERANCE = 2e-37f;
constexpr auto  MATH_FLOAT_SMALL = 1.0e-37f;

class MathUtil {
public:
    inline static void crossVec3(const float* v1, const float* v2, float* dst)
    {
        float x = (v1[1] * v2[2]) - (v1[2] * v2[1]);
        float y = (v1[2] * v2[0]) - (v1[0] * v2[2]);
        float z = (v1[0] * v2[1]) - (v1[1] * v2[0]);

        dst[0] = x;
        dst[1] = y;
        dst[2] = z;
    }
};