#include "test_success.h"
#import <AppKit/AppKit.h>
#import "cocoa_application_interface.h"
#import "AppDelegate.h"
#import "logger.h"

#include <iostream>

// ================ Cocoa Application ================
void initCocoa() {
    AppDelegate* app_delegate = [[AppDelegate alloc] init];
    if (app_delegate == nil) {
        ndLog(ERR, "Failed to initializing AppDelegate: Terminating");
        exit(-1);
    }

    [NSApplication sharedApplication];
    [NSApp setDelegate:app_delegate];
    ndLog(SUC, INT_SetAppDelegate);

    if (![[NSRunningApplication currentApplication] isFinishedLaunching]) {
        [NSApp run];
    } else {
        ndLog(ERR, "NSApplication failed to finish launching");
        exit(-1);
    }
}

void pollEventsCocoa() {
    while (true) {
        NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny 
                                            untilDate:[NSDate distantPast] 
                                               inMode:NSDefaultRunLoopMode 
                                              dequeue:YES];
        if (event == nil) {
            break;
        }

        [NSApp sendEvent:event];
    }
}


// ================ Windows ================
void initWindowBlock() {
    ndLog(SUC, "init Window Block");
}
