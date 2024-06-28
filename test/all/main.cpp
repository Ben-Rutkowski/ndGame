#include "test_success.h"
#include "test_case.hpp"

TestSuite cocoa_application( "../cocoa_application/program.log", {
    {
        "Initialize Cocoa Application",
        INT_SetAppDelegate,
        APP_AppFinishLaunch
    }
});

TestSuite circular_queue( "../circular_queue/program.log", {
    {
        "Circular Queue",
        UNIT_Success
    }
});

TestSuite event_manager( "../event_manager/program.log", {
    {
        "Event Manager Null Callback",
        MOD_EventManagerNullCallback
    },
    {
        "Event Manager Linking and Polling",
        UNIT_Success " event_one",
        UNIT_Success " event_one",
        UNIT_Success " event_two",
        UNIT_Success " event_three",
    }
});

int main() {
    cocoa_application.evaluate();
    circular_queue.evaluate();
    event_manager.evaluate();
}
