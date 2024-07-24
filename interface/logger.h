#ifndef LOGGER_C_H
#define LOGGER_C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <pthread.h>

typedef enum Logger_LogLevel{
    EMP, LOG, ERR, WAR, SUC
} Logger_LogLevel;


// --- Extern ---
extern FILE*           Logger_log_file;
extern pthread_mutex_t Logger_log_mutex;
extern struct timeval  Logger_init_time_micro;


// --- Global Functions ---
void Logger_initLog(const char* filename);
void Logger_taredownLog();

void ndLog(Logger_LogLevel level, const char* message, ...);
void ndLogFast(const char* message);

void ndLogVec(Logger_LogLevel level, float* array_ptr, int N);
void ndLogVeci(Logger_LogLevel level, int* array_ptr, int N);
void ndLogMat(Logger_LogLevel level, float* array_ptr, int M, int N);

#ifdef __cplusplus
}
#endif

#endif
