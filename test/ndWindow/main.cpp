#include "cocoa_application_interface.h"
#include "logger_wrapper.hpp" 
#include "window_cocoa_TEST.hpp"
static ndLogger program_log("program.log");

int main() {
    initCocoa();
    initWindowBlockArrayCocoa();

    int window_0 = createWindowCocoa(800, 600, "ndWindow Test");
    int window_1 = createWindowCocoa(400, 200, "ndWindow Test");

    TEST_0_ndWindow_compareWindowSize(window_0, 800, 600);
    TEST_0_ndWindow_compareWindowSize(window_1, 400, 200);
}
