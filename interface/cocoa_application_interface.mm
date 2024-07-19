#import <AppKit/AppKit.h>
#import "cocoa_application_interface.h"
#import "AppDelegate.h"
#import "WindowBlock.h"
#import "logger.h"

#include "test_success.h"
#include <iostream>

// ================ Cocoa Application ================
void cocoaIntInit() {
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

void cocoaIntPollEvents() {
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

void cocoaIntInitWindowBlockArray() {
    if (WINDOW_BLOCK_ARRAY == nil) {
        WINDOW_BLOCK_ARRAY = [[NSMutableArray alloc] init];
    }

    if (WINDOW_BLOCK_ARRAY != nil) {
        ndLog(SUC, INT_InitWindowBlock);
    }
}
 
void cocoaIntLinkEventManagerToWindow(int window, 
                                   void* event_manager_ptr, 
                                   QueueEventCallback callback)
{
    if (WINDOW_BLOCK_ARRAY != nil) {
        WindowBlock* window_block = WINDOW_BLOCK_ARRAY[window];
        [window_block.event_mananger_interface setEventManager:event_manager_ptr
                                            queueEventCallback:callback];
    }
}

void cocoaIntShowWindow(int window) {
    if (WINDOW_BLOCK_ARRAY != nil) {
        WindowBlock* window_block = WINDOW_BLOCK_ARRAY[window];
        [window_block.window makeKeyAndOrderFront:nil];
    }
}

int cocoaIntCreateWindow(int width, int height, const char* title) {
    NSRect    frame     = NSMakeRect(0, 0, width, height);
    NSString* title_s   = [NSString stringWithUTF8String:title];
    WindowBlock* window_block = [[WindowBlock alloc] initWithFrame:frame 
                                                             title:title_s];
    if (WINDOW_BLOCK_ARRAY != nil) {
        [WINDOW_BLOCK_ARRAY addObject:window_block];
    }

    return [WINDOW_BLOCK_ARRAY count] - 1;
}

int cocoaIntShouldWindowClose(int window) {
    if (WINDOW_BLOCK_ARRAY != nil) {
        WindowBlock* window_block = WINDOW_BLOCK_ARRAY[window];
        return window_block.window_delegate.ndclose_window == YES;
    } else {
        return true;
    }
}

void* cocoaIntGetNdWindow(int window) {
    return (__bridge void*)WINDOW_BLOCK_ARRAY[window];
}

