#ifndef COCOA_APPLICATION_INTERFACE_H
#define COCOA_APPLICATION_INTERFACE_H

// ================ Cocoa Application ================
void cocoaIntInit();
void cocoaIntPollEvents();


// ================ Windows ================
typedef void (*QueueEventCallback)(void*, unsigned int);

void cocoaIntInitWindowBlockArray();
int  cocoaIntCreateWindow(int width, int height, const char* title);
void cocoaIntLinkEventManagerToWindow(int window, 
                                   void* event_manager_ptr, 
                                   QueueEventCallback callback);

void* cocoaIntGetNdWindow(int window);

#endif
