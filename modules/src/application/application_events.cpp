#include "application.hpp"

void ndApplication::propogateEvent(ndEvent* event) {
    if (nd_window) nd_window->runEvent(event);

    propogateEvent_TestHook(event);
}
