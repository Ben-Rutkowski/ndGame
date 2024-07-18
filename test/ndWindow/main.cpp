#include "cocoa_application_interface.h"
#include "logger_wrapper.hpp" 
#include "window_cocoa_TEST.hpp"
static ndLogger program_log("program.log");

int main() {
    initCocoa();
    pollEventsCocoa();
    initWindowBlockArrayCocoa();

    int window_0 = createWindowCocoa(800, 600, "ndWindow Test 0");
    int window_1 = createWindowCocoa(400, 200, "ndWindow Test 1");

    TEST_0_ndWindow_compareWindowSize(window_0, 800, 600);
    TEST_0_ndWindow_compareWindowSize(window_1, 400, 200);

    // TEST_1_ndWindow_showWindow(window_0);
    // while (true) {
    //     pollEventsCocoa();
    // }
}
