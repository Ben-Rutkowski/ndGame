#include "logger.hpp"
#include <iostream>

ndLogger::ndLogger(const char* filename) {
    Logger_initLog(filename);
}

ndLogger::~ndLogger() {
    Logger_taredownLog();
}
