#ifndef EVENT_MANAGER_COCOA_TEST_HPP
#define EVENT_MANAGER_COCOA_TEST_HPP

typedef void(*CALLBACK_0)(void*, unsigned int);

void TEST_init();
void TEST_0_EventManagerInterface_nullCallback();
void TEST_1_EventManagerInterface_setEventManagerCallback(void* event_manager_ptr, CALLBACK_0 callback);
void TEST_2_EventManagerInterface_queueEvent(unsigned int type);

#endif
