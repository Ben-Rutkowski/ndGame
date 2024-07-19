#include "cocoa_application_interface.h"
#include "event_manager.hpp"
#include "window.hpp"

void ndWindow::runEvent(ndEvent* event) {
    switch (event->type) {
        case ndEventType::START_LOOP: onStartLoop(event); break;
        default: break;
    }
}


// ================ Run Loop ================
void ndWindow::onStartLoop(ndEvent* event) {
    cocoaIntShowWindow(window_id);
}
