#include "logger.h"
#include "test_success.h"
#import "cocoa_application_interface.h"
#import "WindowBlock.h"
#import "window_cocoa_TEST.hpp"

void TEST_0_ndWindow_compareWindowSize(unsigned int window, int comp_width, int comp_height) {
    WindowBlock* window_block = (__bridge WindowBlock*)cocoaIntGetNdWindow(window);
    NSView* view = [window_block.window contentView];
    float width  = (float)view.frame.size.width;
    float height = (float)view.frame.size.height;

    if ((float)comp_width == width && (float)comp_height == height) {
        ndLog(SUC, UNIT_Success);
    } else {
        ndLog(SUC, UNIT_Failure);
    }
}

void TEST_1_ndWindow_showWindow(unsigned int window) {
    WindowBlock* window_block = (__bridge WindowBlock*)cocoaIntGetNdWindow(window);
    [window_block.window makeKeyAndOrderFront:nil];
}

void TEST_2_ndWindow_queueEventFromWindow(unsigned int window, unsigned int type) {
    WindowBlock* window_block = (__bridge WindowBlock*)cocoaIntGetNdWindow(window);
    [window_block.event_mananger_interface queueEvent:type];
}
