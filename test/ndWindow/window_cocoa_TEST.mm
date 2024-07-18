#include "logger.h"
#include "test_success.h"
#import "cocoa_application_interface.h"
#import "ndWindow.h"
#import "window_cocoa_TEST.hpp"

void TEST_0_ndWindow_compareWindowSize(int window, int comp_width, int comp_height) {
    ndWindow* nd_window = (__bridge ndWindow*)getNdWindowCocoa(window);
    NSView* view = [nd_window.window contentView];
    float width  = (float)view.frame.size.width;
    float height = (float)view.frame.size.height;

    if ((float)comp_width == width && (float)comp_height == height) {
        ndLog(SUC, UNIT_Success);
    } else {
        ndLog(SUC, UNIT_Failure);
    }
}
