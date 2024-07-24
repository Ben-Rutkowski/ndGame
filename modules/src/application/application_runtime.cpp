#include "cocoa_application_interface.h"
#include "logger.h"
#include "event_manager.hpp"
#include "application.hpp"
#include "test_success.h"

void ndApplication::startRunLoop() {
    ndLog(LOG, "Starting Application Runtime");
    event_manager.queueEvent(
        ndEvent(ndEventType::START_LOOP, APP_StartLoop)
    );
    event_manager.pollEvents();

    while (!nd_window->shouldClose()) {
        cocoaIntPollEvents();
    }
}
