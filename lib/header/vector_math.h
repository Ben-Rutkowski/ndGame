#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#ifdef __cplusplus
extern "C" {
#endif

// ================ Vectors ================
typedef struct C_Vector2 {
    float v[2];
} C_Vector2;

typedef struct C_Vector3 {
    float v[3];
} C_Vector3;

typedef struct C_Vector4 {
    float v[4];
} C_Vector4;

typedef struct C_Vector2i {
    int v[2];
} C_Vector2i;

typedef struct C_Vector3i {
    int v[3];
} C_Vector3i;

typedef struct C_Vector4i {
    int v[4];
} C_Vector4i;


// ================ Matrices ================
typedef struct C_Matrix2x2 {
    float A[2*2];
} C_Matrix2x2;

typedef struct C_Matrix3x3 {
    float A[3*3];
} C_Matrix3x3;

typedef struct C_Matrix4x4 {
    float A[4*4];
} C_Matrix4x4;

#ifdef __cplusplus
}
#endif

#endif
