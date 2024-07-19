#include "logger.h"
#include "cocoa_application_interface.h"
#include "test_success.h"
#include "window.hpp"

ndWindow::ndWindow(int width, int height, const char* title)
:event_manager_ptr(nullptr)
{
    window_id = cocoaIntCreateWindow(width, height, title);
    ndLog(SUC, MOD_CreateNdWindow);
}

void ndWindow::setEventManager(EventManager* ptr, QueueEventCallback callback) {
    event_manager_ptr = ptr;
    cocoaIntLinkEventManagerToWindow(window_id, (void*)event_manager_ptr, callback);
}


// ================ Control ================
void ndWindow::showWindow() {
    cocoaIntShowWindow(window_id);
}

bool ndWindow::shouldClose() {
    return cocoaIntShouldWindowClose(window_id);
}
