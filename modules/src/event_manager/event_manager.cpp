#include "logger.h"
#include "event_manager.hpp"
#include "test_success.h"

// ================ EventManager: Initialization ================
EventManager::EventManager(int initial_queue_size)
:event_queue(initial_queue_size, ndEvent(ndEventType::NULLTYPE)),
 event_callback(EventManager::nullEventCallback) {}

void EventManager::linkEventManager(void* ptr, EVENT_CALLBACK callback) {
    event_callback = callback;
    obj_ptr = ptr;
}


// ================ EventManager: Operations ================
void EventManager::pollEvents() {
    mutex.lock();
    while (!event_queue.isEmpty()) {
        propogateCurrentEvent();
        event_queue.dequeue();
    }
    mutex.unlock();
}

void EventManager::queueEvent(ndEvent event) {
    mutex.lock();
    event_queue.enqueue(event);
    mutex.unlock();
}


// ================ EventManager: Private Operations ================
void EventManager::nextEvent() {
    mutex.lock();
    event_queue.dequeue();
    mutex.unlock();
}

void EventManager::propogateCurrentEvent() {
    ndEvent& event = event_queue.current();
    event_callback(obj_ptr, &event);
}


// ================ EventManager: Static ================
void EventManager::nullEventCallback(void*, ndEvent*) {
    ndLog(ERR, MOD_EventManagerNullCallback);
}

void EventManager::queueEventCocoaCallback(void* ptr, unsigned int type) {
    EventManager* event_manager_ptr = (EventManager*)ptr;
    switch (type) {
        case (unsigned int)ndEventType::DEBUG: {
            event_manager_ptr->queueEvent(ndEvent(ndEventType::DEBUG, TEST_OBJ_COCOA));
            break;
        }
        default: break;
    }
}
