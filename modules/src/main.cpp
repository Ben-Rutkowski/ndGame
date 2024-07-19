#include "cocoa_application_interface.h"
#include "logger_wrapper.hpp"
#include "application.hpp"

static ndLogger program_log("program.log");

static ndApplication nd_app;

int main() {
    cocoaIntInit();
    cocoaIntInitWindowBlockArray();

    // ndWindow* nd_window
}
