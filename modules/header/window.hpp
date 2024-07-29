#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "cocoa_application_interface.h"
#include "event_manager.hpp"

class ndWindow {

// --- Attributes ---
private:
    unsigned int window_id;
    EventManager* event_manager_ptr;


// --- Initialization ---
public:
    ndWindow(int width, int height, const char* title);

    void setEventManager(EventManager* ptr, QueueEventCallback callback);

// --- Control ---
public:
    void showWindow();
    bool shouldClose();


// --- Events ---
public:
    void runEvent(ndEvent* event);

    void onStartLoop(ndEvent* event);

};

#endif
