#include "event_manager_cocoa_TEST.hpp"
#include "test_success.h"
#include "event_manager.hpp"
#include "logger_wrapper.hpp"

static ndLogger program_log("program.log");

void test_callback(void* obj, ndEvent* event) {
    ndLog(SUC, "%s", event->getTag());
}


int main() {
    EventManager event_manager;

    ndEvent event_0(ndEventType::DEBUG);
    ndEvent event_1(ndEventType::DEBUG);
    ndEvent event_2(ndEventType::DEBUG);
    event_0.setTag(TEST_OBJ_0);
    event_1.setTag(TEST_OBJ_1);
    event_2.setTag(TEST_OBJ_2);

    event_manager.queueEvent(event_0);
    event_manager.pollEvents();

    event_manager.linkEventManager(nullptr, test_callback);
    event_manager.queueEvent(event_0);
    event_manager.queueEvent(event_0);
    event_manager.queueEvent(event_1);
    event_manager.queueEvent(event_2);
    event_manager.pollEvents();

    TEST_init();
    TEST_0_EventManagerInterface_nullCallback();
    TEST_1_EventManagerInterface_setEventManagerCallback(&event_manager, EventManager::queueEventCocoaCallback);
    TEST_2_EventManagerInterface_queueEvent((unsigned int)ndEventType::DEBUG);
    event_manager.pollEvents();
}
