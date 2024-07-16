#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "logger.h"

class ndLogger {
public:
    ndLogger(const char* filename) {
        Logger_initLog(filename);
    }

    ~ndLogger() {
        Logger_taredownLog();
    }
};

#endif
