#include "logger.h"
#import "WindowBlock.h"
#import "event_manager_interface.h"

@implementation WindowBlock

- (instancetype) initWithFrame:(NSRect)frame 
                         title:(NSString*)title 
{
    self = [super init];
    if (self) {
        NSWindowStyleMask style = NSWindowStyleMaskClosable | 
                                  NSWindowStyleMaskTitled | 
                                  NSWindowStyleMaskResizable; 

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
        id<MTLDevice> device = MTLCreateSystemDefaultDevice();
        _view = [[View alloc] initWithFrame:frame 
                                     device:device];
        [_window.contentView addSubview:_view];

        // --- Renderer ---
        _renderer = [[Renderer alloc] initWithMTLDevice:device
                                             metalLayer:(CAMetalLayer*)_view.layer];
        [_view setRenderer:_renderer];

        // --- Event Manager Interface ---
        _event_mananger_interface = [[EventManagerInterface alloc] init];
    }

    return self;
}

@end
