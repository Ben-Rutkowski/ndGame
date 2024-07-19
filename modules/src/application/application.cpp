#include "logger.h"
#include "application.hpp"
#include "test_success.h"

// ================ Initialization ================
ndApplication::ndApplication() 
:nd_window(nullptr)
{
    ndLog(SUC, MOD_InitApplication);

    event_manager.linkEventManager((void*)this, ndApplication::eventCallback);
}

ndApplication::~ndApplication() {
    delete nd_window;
}

void ndApplication::linkWindow(ndWindow *ptr) {
    if (!nd_window) {
        nd_window = ptr;
    }
}


// ================ Static ================
void ndApplication::eventCallback(void* ptr, ndEvent* event) {
    ndApplication* app_ptr = (ndApplication*)ptr;
    app_ptr->propogateEvent(event);
}
