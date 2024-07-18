#ifndef EVENT_MANAGER_COCOA_TEST_HPP
#define EVENT_MANAGER_COCOA_TEST_HPP

#import "cocoa_application_interface.h"

void TEST_init();
void TEST_0_EventManagerInterface_nullCallback();
void TEST_1_EventManagerInterface_setEventManagerCallback(void* event_manager_ptr, QueueEventCallback callback);
void TEST_2_EventManagerInterface_queueEvent(unsigned int type);

#endif
