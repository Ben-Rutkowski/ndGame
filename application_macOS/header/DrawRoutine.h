#ifndef DRAW_ROUTINE_H
#define DRAW_ROUTINE_H

#import <QuartzCore/QuartzCore.h>
#import <Metal/Metal.h>

// ================ Protocols ================
@protocol DrawRoutine
- (nonnull instancetype) initWithDevice:(nonnull id<MTLDevice>)device;
- (void) drawInDrawable:(nonnull id<CAMetalDrawable>)drawable
          commandBuffer:(nonnull id<MTLCommandBuffer>)command_buffer;
@end


// ================ Draw Routines ================
@interface NullDrawRoutine : NSObject<DrawRoutine>
@end

#endif
