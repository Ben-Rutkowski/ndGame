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
        "Event Manager Interface Null Callback",
        INT_EventManagerInterfaceNullCallback
    },
    {
        "Event Manager Linking and Polling",
        TEST_OBJ_0,
        TEST_OBJ_0,
        TEST_OBJ_1,
        TEST_OBJ_2
    },
    {
        "Event Manager Interface Linking and Polling",
        TEST_OBJ_COCOA
    }
});

TestSuite nd_application( "../ndApplication/program.log", {
    {
        "Initialize ndApplication",
        MOD_InitApplication
    },
    {
        "ndApplication Event Queue Polling",
        TEST_OBJ_0,
        TEST_OBJ_1
    },
});

TestSuite nd_window( "../ndWindow/program.log", {
    {
        "ndWindow Initialize Window",
        MOD_CreateNdWindow
    },
    {
        "ndWindow EventManagerInterface connection",
        TEST_OBJ_COCOA
    }
});

TestSuite cocoa_window_block( "../cocoa_window_block/program.log", {
    {
        "WindowBlock Comparisions",
        UNIT_Success
    },
    {
        "Initialization Window Delegates",
        APP_InitWindowDelegate,
        APP_InitWindowDelegate
    },
    {
        "WindowBlock and EventManagerInterface",
        INT_EventManagerInterfaceNullCallback,
        TEST_OBJ_COCOA
    }
});

TestSuite cocoa_renderer { "../cocoa_renderer/program.log", {
    {
        "Renderer Creating and Arming Draw Routines",
        APP_CreateDrawRoutine " 0",
        APP_ArmeDrawRoutine " 0",
        APP_CreateDrawRoutine " 0",
        APP_ArmeDrawRoutine " 1",
    }
}};

TestSuite vector_math( "../math/program.log", {
    {
        "Vector and Matrix Tests",
        UNIT_Success
    }
});

int main() {
    circular_queue.evaluate();
    event_manager.evaluate();
    nd_application.evaluate();
    nd_window.evaluate();
    cocoa_application.evaluate();
    cocoa_window_block.evaluate();
    cocoa_renderer.evaluate();
    vector_math.evaluate();
}
