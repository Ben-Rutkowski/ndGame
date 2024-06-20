#ifndef LOGGER_HPP
#define LOGGER_HPP

extern "C" {
    #include "logger.h"
}

class ndLogger {
public:
    ndLogger(const char* filename);
    ~ndLogger();
};

#endif
