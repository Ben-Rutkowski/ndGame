#include "cocoa_application_interface.h"
#include "test_success.h"
#include "event_manager.hpp"
#include "logger.hpp"

static ndLogger program_log("program.log");

#define EVENT_ONE "event_one"
#define EVENT_TWO "event_two"
#define EVENT_THREE "event_three"

void test_callback(void* obj, ndEvent* event) {
    ndLog(SUC, "%s %s", UNIT_Success, event->getTag());
}


int main() {
    EventManager event_manager;

    ndEvent event_one(ndEventType::DEBUG);
    ndEvent event_two(ndEventType::DEBUG);
    ndEvent event_three(ndEventType::DEBUG);
    event_one.setTag(EVENT_ONE);
    event_two.setTag(EVENT_TWO);
    event_three.setTag(EVENT_THREE);

    event_manager.queueEvent(event_one);
    event_manager.pollEvents();

    event_manager.linkEventManager(nullptr, test_callback);
    event_manager.queueEvent(event_one);
    event_manager.queueEvent(event_one);
    event_manager.queueEvent(event_two);
    event_manager.queueEvent(event_three);
    event_manager.pollEvents();
}
