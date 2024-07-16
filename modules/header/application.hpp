#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "event_manager.hpp"

class ndApplication {

// --- Attributes ---
protected:
    EventManager event_manager;


// --- Initialization ---
public:
    ndApplication();


// --- Runtime ---
public:
    void startRunLoop();


// --- Events ---
protected:
    void propogateEvent(ndEvent* event);
    virtual void propogateEvent_TestHook(ndEvent* event) {}


// --- Static ---
public:
    static void eventCallback(void* ptr, ndEvent* event);

};

#endif
