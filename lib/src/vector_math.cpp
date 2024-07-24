#include "vector_math.hpp"
#include "logger.h"

// ================ Math ================
float fastInverseSqrt(float k) {
    long  i;
    float x2, y;
    const float threehalfs = 1.5f;

    x2 = k*0.5f;
    y  = k;
    i  = *(long*)&y;
    i  = 0x5f3759df - (i>>1);
    y  = *(float*)&i;
    y  = y*(threehalfs - (x2*y*y));
    y  = y*(threehalfs - (x2*y*y));

    return y;
}


// ================ Logging ================
void logSUCVec2(const vec2& v) { 
    ndLog(SUC, "[ %.3f, %.3f ]", v.v[0], v.v[1]); 
}

void logSUCVec3(const vec3& v) { 
    ndLog(SUC, "[ %.3f, %.3f, %.3f ]", v.v[0], v.v[1], v.v[2]); 
}

void logSUCVec4(const vec4& v) { 
    ndLog(SUC, "[ %.3f, %.3f, %.3f, %.3f ]", v.v[0], v.v[1], v.v[2], v.v[3]); 
}

void logSUCVec2i(const vec2i& v) { 
    ndLog(SUC, "[ %i, %i ]", v.v[0], v.v[1]); 
}

void logSUCVec3i(const vec3i& v) { 
    ndLog(SUC, "[ %i, %i, %i ]", v.v[0], v.v[1], v.v[2]); 
}

void logSUCVec4i(const vec4i& v) { 
    ndLog(SUC, "[ %i, %i, %i, %i ]", v.v[0], v.v[1], v.v[2], v.v[3]); 
}
