#include "cocoa_application_interface.h"
#include "common.h"
#include "event_manager.hpp"
#include "logger.h"
#include "logger_wrapper.hpp" 
#include "test_success.h"
#include "window_cocoa_TEST.hpp"
static ndLogger program_log("program.log");

static void eventManagerPropogateEvents(void* ptr, ndEvent* event) {
    ndLog(SUC, "%s", event->getTag());
}

int main() {
    ndLog(LOG, "- Initializing -");
    cocoaIntInit();
    cocoaIntPollEvents();
    cocoaIntInitWindowBlockArray();


    ndLog(LOG, "- Creating Windows -");
    unsigned int window_0 = cocoaIntCreateWindow(800, 600, "ndWindow Test 0");
    unsigned int window_1 = cocoaIntCreateWindow(400, 200, "ndWindow Test 1");


    ndLog(LOG, "- Testing Window Parameters -");
    TEST_0_ndWindow_compareWindowSize(window_0, 800, 600);
    TEST_0_ndWindow_compareWindowSize(window_1, 400, 200);


    ndLog(LOG, "- Testing EventManager Callback -");
    EventManager event_manager;
    event_manager.linkEventManager(nullptr, eventManagerPropogateEvents);
 
    TEST_2_ndWindow_queueEventFromWindow(window_0, (unsigned int)ndEventType::DEBUG);

    cocoaIntLinkEventManagerToWindow(window_0, (void*)&event_manager, EventManager::queueEventCocoaCallback);
    TEST_2_ndWindow_queueEventFromWindow(window_0, (unsigned int)ndEventType::DEBUG);
    event_manager.pollEvents();

    int should_close = cocoaIntShouldWindowClose(window_0);
    if (should_close) ndLog(SUC, UNIT_Failure);
    else              ndLog(SUC, UNIT_Success);
    

    // ndLog(LOG, "- Opening Window -");
    // cocoaIntShowWindow(window_0);
    // cocoaIntShowWindow(window_1);
    // while (!cocoaIntShouldWindowClose(window_0) || !cocoaIntShouldWindowClose(window_1)) {
    //     cocoaIntPollEvents();
    // }
}
