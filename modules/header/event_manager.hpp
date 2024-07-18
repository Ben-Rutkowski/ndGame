#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#define DEFAULT_QUEUE_SIZE 32

#include "circular_queue.hpp"

// ================ Enums ================
enum class ndEventType { NULLTYPE = 0,
    /* Application */ START_LOOP,
    /* Other */       DEBUG,
LEN };


// ================ ndEvent ================
class ndEvent {

// --- Attributes ---
public:
    ndEventType type;

private:
    char tag[16];


// --- Initialization ---
public:
    ndEvent() : ndEvent(ndEventType::NULLTYPE) {}
    ndEvent(ndEventType type_in) : type(type_in) {}
    ndEvent(ndEventType type_in, const char* tag_in) : type(type_in) 
    {
        setTag(tag_in);
    }


// --- Debug ---
public:
    void setTag(const char* in) { std::strncpy(tag, in, 16); }
    const char* getTag()        { return tag; }
};


// ================ EventManager ================
typedef void (*EVENT_CALLBACK)(void*, ndEvent*);

class EventManager {

// --- Attributes ---
private:
    CircularQueue<ndEvent> event_queue;
    std::mutex mutex;

    EVENT_CALLBACK event_callback;
    void* obj_ptr;


// --- Initialization ---
public:
    EventManager() : EventManager(DEFAULT_QUEUE_SIZE) {}
    EventManager(int initial_queue_size);
    void linkEventManager(void* ptr, EVENT_CALLBACK callback);


// --- Operations ---
public:
    void pollEvents();
    void queueEvent(ndEvent event);


// --- Private Operations ---
private:
    void nextEvent();
    void propogateCurrentEvent();


// --- Static ---
public:
    static void nullEventCallback(void*, ndEvent*);
    static void queueEventCocoaCallback(void*, unsigned int);

};

#endif
