// #include "logger.h"
#include "application.hpp"

void ndApplication::propogateEvent(ndEvent* event) {
    propogateEvent_TestHook(event);
}
