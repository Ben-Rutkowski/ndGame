#include "logger.h"
#include "test_success.h"
#import "cocoa_application_interface.h"
#import "ndWindow.h"
#import "window_cocoa_TEST.hpp"

void TEST_0_ndWindow_compareWindowSize(int window, int comp_width, int comp_height) {
    ndWindow* nd_window = (__bridge ndWindow*)cocoaIntGetNdWindow(window);
    NSView* view = [nd_window.window contentView];
    float width  = (float)view.frame.size.width;
    float height = (float)view.frame.size.height;

    if ((float)comp_width == width && (float)comp_height == height) {
        ndLog(SUC, UNIT_Success);
    } else {
        ndLog(SUC, UNIT_Failure);
    }
}

void TEST_1_ndWindow_showWindow(int window) {
    ndWindow* nd_window = (__bridge ndWindow*)cocoaIntGetNdWindow(window);
    [nd_window.window makeKeyAndOrderFront:nil];
}

void TEST_2_ndWindow_queueEventFromWindow(int window, unsigned int type) {
    ndWindow* nd_window = (__bridge ndWindow*)cocoaIntGetNdWindow(window);
    [nd_window.event_mananger_interface queueEvent:type];
}
