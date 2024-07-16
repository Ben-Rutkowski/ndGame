#include "logger.h"
#include "application.hpp"
#include "test_success.h"

// ================ Initialization ================
ndApplication::ndApplication() {
    ndLog(SUC, MOD_InitApplication);

    event_manager.linkEventManager((void*)this, ndApplication::eventCallback);
}


// ================ Static ================
void ndApplication::eventCallback(void* ptr, ndEvent* event) {
    ndApplication* app_ptr = (ndApplication*)ptr;
    app_ptr->propogateEvent(event);
}
