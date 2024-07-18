#ifndef COCOA_APPLICATION_INTERFACE_H
#define COCOA_APPLICATION_INTERFACE_H

// ================ Cocoa Application ================
void cocoaIntInit();
void cocoaIntPollEvents();


// ================ Windows ================
typedef void (*QueueEventCallback)(void*, unsigned int);

void cocoaIntInitWindowBlockArray();
void cocoaIntLinkEventManagerToWindow(int window, 
                                   void* event_manager_ptr, 
                                   QueueEventCallback callback);
void cocoaIntShowWindow(int window);

int cocoaIntCreateWindow(int width, int height, const char* title);
int cocoaIntShouldWindowClose(int window);

void* cocoaIntGetNdWindow(int window);

#endif
