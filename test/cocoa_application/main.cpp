#include "logger.hpp"
#include "cocoa_application_interface.h"

static ndLogger log("program.log");

int main() {
    initCocoa();
    pollEventsCocoa();
}
