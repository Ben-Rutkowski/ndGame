#include "test_success.h"
#include "test_case.hpp"
#include <vector>

TestSuite cocoa_application( "../cocoa_application/program.log", {
    {
        "Initialize Cocoa Application",
        INT_SetAppDelegate,
        APP_AppFinishLaunch
    }
});

TestSuite circular_queue( "../circular_queue/program.log", {
    {
        "Testing Circular Queue",
        UNIT_Success
    }
});

int main() {
    cocoa_application.evaluate();
    circular_queue.evaluate();
}
