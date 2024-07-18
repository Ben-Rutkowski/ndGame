#ifndef EVENT_MANAGER_INTERFACE_H
#define EVENT_MANAGER_INTERFACE_H

#import <Foundation/Foundation.h>

typedef void (*QueueEventCallback)(void*, unsigned int);

@interface EventManagerInterface : NSObject

- (void) setEventManager:(void*)event_manager_ptr
         queueEventCallback:(QueueEventCallback)queue_event;

- (void) queueEvent:(unsigned int)type;

@end

#endif
