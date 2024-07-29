#ifndef COCOA_APPLICATION_INTERFACE_H
#define COCOA_APPLICATION_INTERFACE_H

// ================ Cocoa Application ================
void cocoaIntInit();
void cocoaIntPollEvents();


// ================ Windows ================
typedef void (*QueueEventCallback)(void*, unsigned int);

void cocoaIntInitWindowBlockArray();
void cocoaIntLinkEventManagerToWindow(unsigned int window, 
                                   void* event_manager_ptr, 
                                   QueueEventCallback callback);
void cocoaIntShowWindow(unsigned int window);
void cocoaIntArmDrawRoutine(unsigned int window, unsigned int draw_routine);

unsigned int cocoaIntCreateWindow(int width, int height, const char* title);
unsigned int cocoaIntCreateDrawRoutine(unsigned int window, unsigned int draw_routine_id);
unsigned int cocoaIntShouldWindowClose(unsigned int window);

void* cocoaIntGetNdWindow(unsigned int window);

#endif
