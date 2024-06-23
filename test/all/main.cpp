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

int main() {
    cocoa_application.evaluate();
}
