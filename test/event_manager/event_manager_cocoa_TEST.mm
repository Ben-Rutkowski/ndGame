#import "event_manager_cocoa_TEST.hpp"
#import "event_manager_interface.h"

static EventManagerInterface* event_manager_interface;

void TEST_init() {
    event_manager_interface = [[EventManagerInterface alloc] init];
}

void TEST_0_EventManagerInterface_nullCallback() {
    [event_manager_interface queueEvent:0]; 
}

void TEST_1_EventManagerInterface_setEventManagerCallback(void* event_manager_ptr, CALLBACK_0 callback) {
    [event_manager_interface setEventManager:event_manager_ptr queueEventCallback:callback];
}

void TEST_2_EventManagerInterface_queueEvent(unsigned int type) {
    [event_manager_interface queueEvent:type];
}
