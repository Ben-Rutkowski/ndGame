#include "test_success.h"
#include "test_case.hpp"
#include <vector>

std::vector<TestCaseList> cocoa_application = {
    {
        "Initialize Application",
        INT_SetAppDelegate,
        APP_AppFinishLaunch,
    }
};

int main() {
    evaulateBuild("../cocoa_application/program.log", cocoa_application);
}
