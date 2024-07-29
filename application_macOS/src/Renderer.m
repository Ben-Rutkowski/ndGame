#import "Renderer.h"
#include "test_success.h"
#import "DrawRoutine.h"
#import "logger.h"
#import "common.h"

@implementation Renderer
{
    // --- Metal Components ---
    id<MTLDevice>       _device;
    id<MTLCommandQueue> _command_queue;
    id<MTLLibrary>      _library;
    MTLPixelFormat      _view_pixel_format;

    // --- Draw Routines ---
    NSMutableArray<id<DrawRoutine>>* _loaded_draw_routines;
    id<DrawRoutine>                  _armed_draw_routine;
}


// ==== Initialization ====
- (instancetype) initWithMTLDevice:(nonnull id<MTLDevice>)device
                        metalLayer:(nonnull CAMetalLayer*)layer
{
    self = [super init];    
    if (self) {
        _device            = device;
        _command_queue     = [_device newCommandQueue];
        _view_pixel_format = layer.pixelFormat;

        _loaded_draw_routines = [NSMutableArray array];
        unsigned int null_routine = [self createDrawRoutine:NullDrawRoutine_t];
        [self armDrawRoutine:null_routine];
    }

    return self;
}

- (unsigned int) createDrawRoutine:(unsigned int)type {
    id<DrawRoutine> draw_routine = nil;

    switch (type) {
        case NullDrawRoutine_t: {
            draw_routine = [[NullDrawRoutine alloc] initWithDevice:_device];
        }

        default: break;
    }

    if (draw_routine) {
        ndLog(SUC, APP_CreateDrawRoutine " %i", type);
        [_loaded_draw_routines addObject:draw_routine];
        return [_loaded_draw_routines count] - 1;
    } else {
        ndLog(ERR, ERR_FailedToCreateDrawRoutine " %i", type);
        return 0;
    }
}

- (void) armDrawRoutine:(unsigned int)id {
    if (id < [_loaded_draw_routines count]) {
        ndLog(SUC, APP_ArmeDrawRoutine " %i", id);
        _armed_draw_routine = _loaded_draw_routines[id];
    }
}


// ==== Draw ====
- (void) drawInMetalLayer:(CAMetalLayer*)metal_layer {
    // id<CAMetalDrawable> current_drawable = [metal_layer nextDrawable];
    // if (current_drawable == nil) return;

    // id<MTLCommandBuffer> command_buffer = [_command_queue commandBuffer];

    // send command buffer to draw routine
    // add completed handler

    // [command_buffer presentDrawable:current_drawable];
    // [command_buffer commit];
}

@end
