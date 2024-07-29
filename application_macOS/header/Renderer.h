#ifndef RENDERER_H
#define RENDERER_H

#import <MetalKit/MetalKit.h>
#import <QuartzCore/QuartzCore.h>
#import "common.h"

@interface Renderer : NSObject
// --- Initialization ---
- (nonnull instancetype) initWithMTLDevice:(nonnull id<MTLDevice>)device
                                metalLayer:(nonnull CAMetalLayer*)layer;

- (unsigned int) createDrawRoutine:(unsigned int)type;
- (void) armDrawRoutine:(unsigned int)id;

// --- Draw ---
- (void) drawInMetalLayer:(nonnull CAMetalLayer*)metal_layer;
@end

#endif
