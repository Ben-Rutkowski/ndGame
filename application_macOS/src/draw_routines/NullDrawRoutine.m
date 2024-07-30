#import "logger.h"
#include "test_success.h"
#import "DrawRoutine.h"

@implementation NullDrawRoutine
- (instancetype) initWithDevice:(id<MTLDevice>)device {
    self = [super init];
    return self;
}

- (void) drawInDrawable:(id<CAMetalDrawable>)drawable
          commandBuffer:(id<MTLCommandBuffer>)command_buffer 
{
    ndLog(SUC, APP_DrawInNullDrawRoutine);
}
@end
