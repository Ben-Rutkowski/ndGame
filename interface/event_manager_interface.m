#include "logger.h"
#include "test_success.h"
#import "event_manager_interface.h"

static void NullQueueEventCallback(void* ptr, unsigned int type) {
    ndLog(ERR, INT_EventManagerInterfaceNullCallback);
}

@implementation EventManagerInterface
{
    void* _event_manager;
    QueueEventCallback _queue_event_callback;
}

- (instancetype) init {
    self = [super init];
    if (self) {
        _event_manager = NULL;
        _queue_event_callback = NullQueueEventCallback;
    }

    return self;
}

- (void) setEventManager:(void*)event_manager_ptr
         queueEventCallback:(QueueEventCallback)queue_event
{
    _event_manager = event_manager_ptr;
    _queue_event_callback = queue_event;
}

- (void) queueEvent:(unsigned int)type {
    _queue_event_callback(_event_manager, type);
}

@end

