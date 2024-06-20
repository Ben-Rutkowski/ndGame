#include "logger.h"
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

#define LOG_BUFFER_SIZE 10000

FILE*           Logger_log_file = NULL;
pthread_mutex_t Logger_log_mutex;
struct timeval  Logger_init_time;

static const unsigned long MILL = 1000000;
static char buf[LOG_BUFFER_SIZE];

static struct timeval getDiffTime() {
    struct timeval diff_time;
    gettimeofday(&diff_time,NULL);

    long usec_corrected = diff_time.tv_usec;
    if (diff_time.tv_usec < Logger_init_time.tv_usec) {
        usec_corrected   += MILL;
        diff_time.tv_sec -= 1;
    }
    diff_time.tv_sec -= Logger_init_time.tv_sec;
    diff_time.tv_usec = usec_corrected - Logger_init_time.tv_usec;

    return diff_time;
}

static inline void log_message(const char* level, const char* message) {
    struct timeval diff_timeval; 
    struct tm*     diff_tm;
    
    diff_timeval = getDiffTime();
    diff_tm = gmtime(&diff_timeval.tv_sec);

    fprintf(Logger_log_file, "[%i:%i:%i.%06u] ", 
                diff_tm->tm_hour, 
                diff_tm->tm_min, 
                diff_tm->tm_sec, 
                diff_timeval.tv_usec
            );
    fprintf(Logger_log_file, "%s %s\n", level, message);
}

static const char* levelString(Logger_LogLevel level) {
    switch (level) {
        case LOG: return "-   -";
        case ERR: return "-ERR-";
        case WAR: return "-WAR-";
        default:  return "-NUL-";
    }
}

void Logger_initLog(const char *filename) {
    Logger_log_file = fopen(filename, "w");
    if (!Logger_log_file) {
        perror("Failed to open the log file");
        exit(-1);
    }
    pthread_mutex_init(&Logger_log_mutex, NULL);
    gettimeofday(&Logger_init_time,NULL);
    gmtime(&Logger_init_time.tv_sec);
    
    setvbuf(Logger_log_file, buf, _IOFBF, sizeof(buf));
}

void Logger_taredownLog() {
    fclose(Logger_log_file);
    Logger_log_file = NULL;
    pthread_mutex_destroy(&Logger_log_mutex);
}

void ndLog(Logger_LogLevel level, const char* message) {
    if (Logger_log_file == NULL) {
        perror("Failed to write to the log file: log file not open");
        return;
    }

    const char* level_str = levelString(level);

    pthread_mutex_lock(&Logger_log_mutex);
    log_message(level_str, message);
    fflush(Logger_log_file);
    pthread_mutex_unlock(&Logger_log_mutex);
}

void ndLogFast(const char* message) {
    pthread_mutex_lock(&Logger_log_mutex);
    log_message("     ", message);
    pthread_mutex_unlock(&Logger_log_mutex);
}
