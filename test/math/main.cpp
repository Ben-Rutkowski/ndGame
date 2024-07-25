#include "logger.h"
#include "logger_wrapper.hpp"
#include "test_success.h"
#include "vector_math.hpp"
static ndLogger program_log("program.log");

template<typename T>
static void compare(const T* val_0, const T* val_1) {
    bool success = !std::memcmp(val_0, val_1, sizeof(T));

    if (success) {
        ndLog(SUC, UNIT_Success);
    } else {
        ndLog(SUC, UNIT_Failure);
    }
}

static void compareFloatVec(float* val_0, float* val_1, size_t size, float TOL=1e-2) {
    bool success = true;
    for (int i=0; i<size; i++) {
        if (abs(val_0[i] - val_1[i]) > TOL) {
            success = false;
            break;
        }
    }

    if (success) {
        ndLog(SUC, UNIT_Success);
    } else {
        ndLog(SUC, UNIT_Failure);
    }
}

int main() {

    // ================ Vectors ================
    vec4 a, b, c, c_ans;
    float f, f_ans;

    a = { 1.0f, 2.0f, 3.0f, 4.0f };
    b = { 2.0f, 3.0f, 4.0f, 5.0f };

    c = a + b;
    c_ans = { 3.0f, 5.0f, 7.0f, 9.0f };
    compare<vec4>(&c, &c_ans);

    c = a - b;
    c_ans = { -1.0f, -1.0f, -1.0f, -1.0f };
    compare<vec4>(&c, &c_ans);

    c = 3.0f*a;
    c_ans = { 3.0f, 6.0f, 9.0f, 12.0f };
    compare<vec4>(&c, &c_ans);

    f = a.dot(b);
    f_ans = 40.0f;
    compare<float>(&f, &f_ans);

    f = a.dot(a);
    f_ans = 30.0f;
    compare<float>(&f, &f_ans);

    a.add(b);
    c_ans = { 3.0f, 5.0f, 7.0f, 9.0f };
    compare<vec4>(&a, &c_ans);

    a.sub(b);
    c_ans = { 1.0, 2.0, 3.0f, 4.0 };
    compare<vec4>(&a, &c_ans);

    a.scalarMult(3.0f);
    c_ans = { 3.0f, 6.0f, 9.0f, 12.0f };
    compare<vec4>(&a, &c_ans);


    // ================ Matrices ================
    vec3 v, w, w_ans;
    mat2 A, E, F, A_ans;
    mat3 B, C, D, D_ans;

    A = {
        1.0f, 2.0f,
        3.0f, 4.0f
    };

    f = A.get(0,0);
    f_ans = 1.0f;
    compare<float>(&f, &f_ans);

    f = A.get(1,0);
    f_ans = 2.0f;
    compare<float>(&f, &f_ans);

    A.transpose();
    A_ans = {
        1.0f, 3.0f,
        2.0f, 4.0f
    };
    compare<mat2>(&A, &A_ans);

    B = {
        1.0f, 2.0f, 3.0f,
        2.0f, 5.0f, 1.0f,
        5.0f, 9.0f, 1.0f
    };
    C = {
        5.0f, 2.0f, 1.0f,
        9.0f, 7.0f, 1.0f,
        0.0f, 1.0f, 2.0f
    };

    D = B + C;
    D_ans = {
        6.0f,  4.0f,  4.0f,
        11.0f, 12.0f, 2.0f,
        5.0f,  10.0f, 3.0f
    };
    compare<mat3>(&D, &D_ans);
    
    D = B - C;
    D_ans = {
        -4.0f,  0.0f,  2.0f,
        -7.0f, -2.0f,  0.0,
         5.0f,  8.0f, -1.0f
    };
    compare<mat3>(&D, &D_ans);

    A = {
        1.0f, 3.0f,
        2.0f, 4.0f
    };
    E = {
        5.0f, 3.0f,
        1.0f, 2.0f
    };

    F = A*E;
    A_ans = {
        11.0f, 27.0f,
        5.0f,  11.0f
    };
    compare<mat2>(&F, &A_ans);

    v = { 3.0f, 1.0f, 0.0f };

    w = B*v;
    w_ans = { 5.0f, 11.0f, 10.0f };
    compare<vec3>(&w, &w_ans);

    v = { 3.0f, 2.0f, 1.0f };

    v.L2_Normalize();
    w_ans = { 0.802f, 0.535f, 0.265f };
    compareFloatVec(v.v, w_ans.v, 3);

    v.L2_Normalize();
    compareFloatVec(v.v, w_ans.v, 3);
}
