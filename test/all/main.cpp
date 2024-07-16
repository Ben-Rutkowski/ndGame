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
        TEST_OBJ_0,
        TEST_OBJ_0,
        TEST_OBJ_1,
        TEST_OBJ_2
    }
});

TestSuite nd_application( "../ndApplication/program.log", {
    {
        "Initialize ndApplication",
        MOD_InitApplication
    },
    {
        "Event Queue Polling",
        TEST_OBJ_0,
        TEST_OBJ_1
    },
});

int main() {
    cocoa_application.evaluate();
    circular_queue.evaluate();
    event_manager.evaluate();
    nd_application.evaluate();
}
