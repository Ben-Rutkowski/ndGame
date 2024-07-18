#import <AppKit/AppKit.h>
#include <Foundation/Foundation.h>
#import "cocoa_application_interface.h"
#import "AppDelegate.h"
#import "ndWindow.h"
#import "logger.h"

#include "test_success.h"
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
static NSMutableArray* WINDOW_BLOCK_ARRAY = nil;

void initWindowBlockArrayCocoa() {
    WINDOW_BLOCK_ARRAY = [[NSMutableArray alloc] init];
    if (WINDOW_BLOCK_ARRAY != nil) {
        ndLog(SUC, INT_InitWindowBlock);
    }
}

int createWindowCocoa(int width, int height, const char* title) {
    NSRect    frame     = NSMakeRect(0, 0, width, height);
    NSString* title_s   = [NSString stringWithUTF8String:title];
    ndWindow* nd_window = [[ndWindow alloc] initWithFrame:frame 
                                                    title:title_s];
    if (WINDOW_BLOCK_ARRAY != nil) {
        [WINDOW_BLOCK_ARRAY addObject:nd_window];
    }

    return [WINDOW_BLOCK_ARRAY count] - 1;
}

void* getNdWindowCocoa(int window) {
    return (__bridge void*)WINDOW_BLOCK_ARRAY[window];
}
