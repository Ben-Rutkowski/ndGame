#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <iostream>
#include <memory>
#include <thread>

// ================ Enums ================
enum class ndEventType { NULLTYPE = 0,
    DEBUG,
LEN };


// ================ ndEvent ================
class ndEvent {

// --- Attributes ---
public:
    ndEventType type;


// --- Initialization ---
public:
    ndEvent() : ndEvent(ndEventType::NULLTYPE) {}
    ndEvent(ndEventType type_in) : type(type_in) {}
    ndEvent(ndEventType type_in, const char* tag_in) : type(type_in) {
        setTag(tag_in);
    }


// --- Debug ---
public:
    char tag[16];
    void setTag(const char* in) { std::strncpy(tag, in, 16); }
    void print()                { std::cout << tag; }
};


#define DEFAULT_QUEUE_SIZE 32
// ================ EventManager ================
class EventManager {

// --- Attributes ---
private:
    std::mutex mutex;


// --- Initialization ---
public:
    ~EventManager();
    EventManager() : EventManager(DEFAULT_QUEUE_SIZE) {}
    EventManager(int initial_queue_size);


// --- Operations ---
public:

};

#endif
