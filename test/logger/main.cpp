#include <iostream>

extern "C" {
    #include "logger.h"
}

int main() {
    Logger_initLog("program.log");

    const int SIZE = 10;
    float* A = (float*)malloc(SIZE*sizeof(float));
    float* B = (float*)malloc(SIZE*sizeof(float));
    float* C = (float*)malloc(SIZE*sizeof(float));
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            float sum = 0;
            for (int k=0; k<SIZE; k++) {
                sum += A[i+SIZE*k]*B[k+SIZE*j];
            }
            C[i+SIZE*j] = sum;
        }
    }

    ndLog(LOG, "message");
    ndLog(ERR, "error message");
    ndLog(WAR, "warning message");
    ndLogFast("Fast One");
    ndLogFast("Fast One");
    ndLogFast("Fast Two");

    Logger_taredownLog();
}
