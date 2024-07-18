#include "logger.h"
#import "ndWindow.h"

@implementation ndWindow

- (instancetype) initWithFrame:(NSRect)frame 
                         title:(NSString *)title 
{
    self = [super init];
    if (self) {
        NSWindowStyleMask style = NSWindowStyleMaskClosable | NSWindowStyleMaskTitled | NSWindowStyleMaskResizable; 
        _window = [[NSWindow alloc] initWithContentRect:frame 
                                              styleMask:style 
                                                backing:NSBackingStoreBuffered 
                                                  defer:NO];
        [_window setTitle:title];
        [_window center];
        
        // --- Window Delegate ---
        _window_delegate = [[WindowDelegate alloc] init];
        [_window setDelegate:_window_delegate];

        // --- View ---

        // --- Render Switcher ---
    }

    return self;
}

@end
