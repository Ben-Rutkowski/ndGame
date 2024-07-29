#include "cocoa_application_interface.h"
#include "common.h"
#include "logger_wrapper.hpp"
static ndLogger program_log("program.log");

int main() {
    cocoaIntInit();
    cocoaIntInitWindowBlockArray();

    unsigned int window = cocoaIntCreateWindow(800, 600, "Renderer Test");
    unsigned int null_draw_routine = cocoaIntCreateDrawRoutine(window, NullDrawRoutine_t);
    cocoaIntArmDrawRoutine(window, null_draw_routine);
}
