#include "cocoa_application_interface.h"
#include "event_manager.hpp"
#include "logger_wrapper.hpp"
#include "test_success.h"
#include "window.hpp"
static ndLogger program_log("program.log");

static void TEST_propogateEvent(void* ptr, ndEvent* event) {
    ndLog(SUC, "%s", event->getTag());
}

static void TEST_QueueEventCallback(void* ptr, unsigned int type) {
    EventManager* event_manager_ptr = (EventManager*)ptr;

    switch (type) {
        case (unsigned int)ndEventType::DEBUG:
            event_manager_ptr->queueEvent(
                ndEvent(ndEventType::DEBUG, TEST_OBJ_COCOA)
            );
    }
}

int main() {
    cocoaIntInit();
    cocoaIntInitWindowBlockArray();

    ndWindow nd_window(800, 600, "TEST_window_0");

    EventManager event_manager;
    event_manager.linkEventManager(nullptr, TEST_propogateEvent);

    nd_window.setEventManager(&event_manager, TEST_QueueEventCallback);

    TEST_QueueEventCallback((void*)&event_manager, (unsigned int)ndEventType::DEBUG);
    event_manager.pollEvents();
}
