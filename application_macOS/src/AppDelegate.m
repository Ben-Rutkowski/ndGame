#include <AppKit/AppKit.h>
#include <Foundation/Foundation.h>
#import "test_success.h"
#import "AppDelegate.h"
#import "logger.h"

@implementation AppDelegate

- (void) applicationWillFinishLaunching:(NSNotification*)notification {
}

- (void) applicationDidFinishLaunching:(NSNotification*)notification {
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];

    NSEvent* event = [NSEvent otherEventWithType:NSEventTypeApplicationDefined 
                                        location:NSMakePoint(0,0) 
                                   modifierFlags:0 
                                       timestamp:0 
                                    windowNumber:0 
                                         context:nil 
                                         subtype:0 
                                           data1:0 
                                           data2:0];
    [NSApp postEvent:event atStart:YES];
    [NSApp stop:nil];

    ndLog(SUC, APP_AppFinishLaunch);
}

@end
