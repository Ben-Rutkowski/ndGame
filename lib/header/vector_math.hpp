#ifndef VECTOR_MATH_HPP
#define VECTOR_MATH_HPP

#include "vector_math.h"
#include <iostream>


// ================ Constants ================
template<typename T> struct CONSTANTS {};
template<> struct CONSTANTS<float> {
    static constexpr float zero = 0.0f;
    static constexpr float one  = 1.0f;
};

template<> struct CONSTANTS<int> {
    static constexpr int zero = 0;
    static constexpr int one  = 1;
};


// ================ Vectors ================
template<typename T, typename VEC, int N>
class CPP_VECTOR_TEMP : public VEC {

// ---- Initialization ----
public:
    inline T& operator[](int n) {
        return this->v[n];
    }

// ---- Operations ----
public:
    CPP_VECTOR_TEMP<T,VEC,N> operator+(const CPP_VECTOR_TEMP<T,VEC,N>& b) const {
        CPP_VECTOR_TEMP<T,VEC,N> output;
        for (int i=0; i<N; i++) {
            output.v[i] = this->v[i] + b.v[i];
        }
        return output;
    } 

    CPP_VECTOR_TEMP<T,VEC,N> operator-(const CPP_VECTOR_TEMP<T,VEC,N>& b) const {
        CPP_VECTOR_TEMP<T,VEC,N> output;
        for (int i=0; i<N; i++) {
            output.v[i] = this->v[i] - b.v[i];
        }
        return output;
    } 

    T dot(const CPP_VECTOR_TEMP<T,VEC,N>& b) const {
        T output = CONSTANTS<T>::zero;
        for (int i=0; i<N; i++) {
            output += this->v[i]*b.v[i];
        }
        return output;
    } 

// ---- Mutations ----
public:
    void add(const CPP_VECTOR_TEMP<T,VEC,N>& b) {
        for (int i=0; i<N; i++) {
            this->v[i] += b.v[i];
        }
    }

    void sub(const CPP_VECTOR_TEMP<T,VEC,N>& b) {
        for (int i=0; i<N; i++) {
            this->v[i] -= b.v[i];
        }
    }

    void scalarMult(const T k) {
        for (int i=0; i<N; i++) {
            this->v[i] *= k;
        }
    }

    void L2_Normalize() {
        float k = 1.0f/sqrt(this->dot(*this));
        scalarMult(k);
    }

// ---- Debuging ----
public:
    void print() {
        for (int i=0; i<N-1; i++) {
            std::cout << this->v[i] << " ";
        }
        std::cout << this->v[N-1] << std::endl;
    }
};


// ---------------- Overloading Operators ----------------
template<typename T, typename VEC, int N>
CPP_VECTOR_TEMP<T,VEC,N> operator*(float k, const CPP_VECTOR_TEMP<T,VEC,N>& vec) {
    CPP_VECTOR_TEMP<T,VEC,N> output;
    for (int i=0; i<N; i++) {
        output.v[i] = k*vec.v[i];
    }
    return output;
}


// ---------------- Typedefs ----------------
typedef CPP_VECTOR_TEMP<float,C_Vector2,2> vec2;
typedef CPP_VECTOR_TEMP<float,C_Vector3,3> vec3;
typedef CPP_VECTOR_TEMP<float,C_Vector4,4> vec4;

typedef CPP_VECTOR_TEMP<int,C_Vector2i,2> vec2i;
typedef CPP_VECTOR_TEMP<int,C_Vector3i,3> vec3i;
typedef CPP_VECTOR_TEMP<int,C_Vector4i,4> vec4i;


// ================ Matrices ================
template<typename T, typename MAT, typename VEC, int M, int N>
class CPP_MATRIX_TEMP : public MAT {

// --- Initialization ---
public:
    inline T& get(int i, int j) {
        return this->A[i + j*M];
    }

// --- Operations ---
public:
    CPP_MATRIX_TEMP<T,MAT,VEC,M,N> operator+(const CPP_MATRIX_TEMP<T,MAT,VEC,M,N>& B) const {
        CPP_MATRIX_TEMP<T,MAT,VEC,M,N> output;
        for (int i=0; i<M*N; i++) {
            output.A[i] = this->A[i] + B.A[i];
        }
        return output;
    }

    CPP_MATRIX_TEMP<T,MAT,VEC,M,N> operator-(const CPP_MATRIX_TEMP<T,MAT,VEC,M,N>& B) const {
        CPP_MATRIX_TEMP<T,MAT,VEC,M,N> output;
        for (int i=0; i<M*N; i++) {
            output.A[i] = this->A[i] - B.A[i];
        }
        return output;
    }

    CPP_VECTOR_TEMP<T,VEC,N> operator*(const CPP_VECTOR_TEMP<T,VEC,M>& v) const {
        CPP_VECTOR_TEMP<T,VEC,N> output;
        for (int i=0; i<M; i++) {
            output[i] = CONSTANTS<T>::zero;
            for (int j=0; j<N; j++) {
                output[i] += this->A[i + j*M]*v.v[j];
            }
        }
        return output;
    }

    template<int P>
    CPP_MATRIX_TEMP<T,MAT,VEC,M,P> operator*(const CPP_MATRIX_TEMP<T,MAT,VEC,N,P>& B) const {
        CPP_MATRIX_TEMP<T,MAT,VEC,M,P> output;
        T term;
        for (int i=0; i<M; i++) {
            for (int j=0; j<P; j++) {
                term = CONSTANTS<T>::zero;
                for (int k=0; k<N; k++) {
                    term += this->A[i + k*M]*B.A[k + j*N];
                }
                output.A[i + j*M] = term;
            }
        }
        return output;
    }

// --- Mutations ---
public:
    void transpose() {
        T term;
        for (int i=1; i<M; i++) {
            for (int j=0; j<i; j++) {
                term = get(i,j);
                get(i,j) = get(j,i);
                get(j,i) = term;
            }
        }
    }

// --- Debuging ---
public:
    void print() {
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                std::cout << get(i,j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

// ---------------- Typedefs ----------------
typedef CPP_MATRIX_TEMP<float,C_Matrix2x2,C_Vector2,2,2> mat2;
typedef CPP_MATRIX_TEMP<float,C_Matrix3x3,C_Vector3,3,3> mat3;
typedef CPP_MATRIX_TEMP<float,C_Matrix4x4,C_Vector4,4,4> mat4;


// ----
void math_debug();

#endif
