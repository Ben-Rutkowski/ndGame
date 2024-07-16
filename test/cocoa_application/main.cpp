#include "logger_wrapper.hpp"
#include "cocoa_application_interface.h"

static ndLogger program_log("program.log");

int main() {
    initCocoa();
    pollEventsCocoa();
}
