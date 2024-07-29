#include "logger.h"
#import "View.h"
#import <Metal/Metal.h>
#import <AppKit/AppKit.h>
#import <QuartzCore/QuartzCore.h>

@implementation View
{
    CAMetalLayer* _metal_layer;
    Renderer*     _renderer;
}


// ================ Initialization ================
- (nonnull instancetype) initWithFrame:(CGRect)frame 
                                device:(nonnull id<MTLDevice>)device
{
    self = [super initWithFrame:frame];
    if (self) {
        self.wantsLayer = YES;
        self.layerContentsRedrawPolicy = NSViewLayerContentsRedrawDuringViewResize;
        self.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;

        _metal_layer = (CAMetalLayer*)self.layer;
        self.layer.delegate = self;

        _metal_layer.device = device;
        _metal_layer.pixelFormat = MTLPixelFormatBGRA8Unorm_sRGB;
        _metal_layer.displaySyncEnabled = NO;
    }

    return self;
}


// ================ Draw ================
- (void) draw {
    if (_renderer) {
        [_renderer drawInMetalLayer:_metal_layer];
    }
}


// ================ CAMetalLayer Delegates ================
- (void) displayLayer:(CALayer*)layer {
    [self draw];
}

- (void) drawLayer:(CALayer*)layer 
         inContext:(CGContextRef)ctx 
{
    [self draw];
}

- (void) drawRect:(NSRect)dirtyRect {
    [self draw];
}


// ================ NSView Functions ================
- (CALayer*) makeBackingLayer {
    return [CAMetalLayer layer];
}

- (void) viewDidMoveToWindow {
    [super viewDidMoveToWindow];
}

- (void) viewDidChangeBackingProperties {
    [super viewDidChangeBackingProperties];
}

- (void) setFrameSize:(NSSize)size {
    [super setFrameSize:size];
}

- (void) setBoundsSize:(NSSize)size {
    [super setBoundsSize:size];
}

@end
