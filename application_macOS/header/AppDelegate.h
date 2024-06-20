#ifndef APP_DELEGATE_COCOA_H
#define APP_DELEGATE_COCOA_H

#import <AppKit/AppKit.h>

@interface AppDelegate : NSObject<NSApplicationDelegate>
- (void) applicationWillFinishLaunching:(NSNotification*)notification;
- (void) applicationDidFinishLaunching:(NSNotification*)notification;
@end

#endif
