#include "event_manager.hpp"
#include "logger.hpp"
#include "test_success.h"

static ndLogger program_log("program.log");

void test_callback(void* obj, ndEvent* event) {
    std::cout << event->getTag() << std::endl;
}


int main() {
    EventManager event_manager;

    ndEvent test_event(ndEventType::DEBUG);
    test_event.setTag("event_one");
    ndEvent test_event2(ndEventType::DEBUG);
    test_event2.setTag("event_two");

    event_manager.queueEvent(test_event);
    event_manager.queueEvent(test_event2);
    event_manager.pollEvents();

    event_manager.linkEventManager(nullptr, test_callback);
    event_manager.queueEvent(test_event2);
    event_manager.queueEvent(test_event);
    event_manager.pollEvents();
}
