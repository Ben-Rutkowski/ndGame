#include "application.hpp"
#include "event_manager.hpp"
#include "logger_wrapper.hpp"
#include "test_success.h"
static ndLogger program_log("program.log");

class TEST_ndApplication : public ndApplication {
public:
    void TEST_queueEvent() {
        ndEvent event_0(ndEventType::DEBUG);
        ndEvent event_1(ndEventType::DEBUG);
        event_0.setTag(TEST_OBJ_0);
        event_1.setTag(TEST_OBJ_1);
        event_manager.queueEvent(event_0);
        event_manager.queueEvent(event_1);
    }

    void TEST_pollEvents() {
        event_manager.pollEvents();
    }

    void propogateEvent_TestHook(ndEvent* event) {
        ndLog(SUC, "%s", event->getTag());
    }
};

int main() {
    TEST_ndApplication ndApp;
    ndApp.TEST_queueEvent();
    ndApp.TEST_pollEvents();
}
