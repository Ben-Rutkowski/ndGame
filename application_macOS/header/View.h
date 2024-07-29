#ifndef VIEW_COCOA_H
#define VIEW_COCOA_H

#import <AppKit/AppKit.h>
#import <QuartzCore/CAMetalLayer.h>
#import <Metal/Metal.h>
#import "Renderer.h"

@interface View : NSView<CALayerDelegate>

@property (atomic, weak, nullable) Renderer* renderer;

// --- Initializiation ---
- (nonnull instancetype) initWithFrame:(CGRect)frame 
                                device:(nonnull id<MTLDevice>)device;

// --- Draw ---
- (void) draw;

@end

#endif
