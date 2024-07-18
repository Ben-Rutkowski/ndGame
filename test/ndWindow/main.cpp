#include "cocoa_application_interface.h"
#include "event_manager.hpp"
#include "logger_wrapper.hpp" 
#include "window_cocoa_TEST.hpp"
static ndLogger program_log("program.log");

static void eventManagerPropogateEvents(void* ptr, ndEvent* event) {
    ndLog(SUC, "%s", event->getTag());
}

int main() {
    initCocoa();
    pollEventsCocoa();
    initWindowBlockArrayCocoa();

    int window_0 = createWindowCocoa(800, 600, "ndWindow Test 0");
    int window_1 = createWindowCocoa(400, 200, "ndWindow Test 1");

    TEST_0_ndWindow_compareWindowSize(window_0, 800, 600);
    TEST_0_ndWindow_compareWindowSize(window_1, 400, 200);

    // TEST_1_ndWindow_showWindow(window_0);
    // while (true) {
    //     pollEventsCocoa();
    // }

    EventManager event_manager;
    event_manager.linkEventManager(nullptr, eventManagerPropogateEvents);
 
    TEST_2_ndWindow_queueEventFromWindow(window_0, (unsigned int)ndEventType::DEBUG);

    linkEventManagerToWindowCocoa(window_0, (void*)&event_manager, EventManager::queueEventCocoaCallback);
    TEST_2_ndWindow_queueEventFromWindow(window_0, (unsigned int)ndEventType::DEBUG);
    event_manager.pollEvents();

}
