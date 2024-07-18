#ifndef COCOA_APPLICATION_INTERFACE_H
#define COCOA_APPLICATION_INTERFACE_H

// ================ Cocoa Application ================
void initCocoa();
void pollEventsCocoa();


// ================ Windows ================
typedef void (*QueueEventCallback)(void*, unsigned int);

void initWindowBlockArrayCocoa();
int  createWindowCocoa(int width, int height, const char* title);
void linkEventManagerToWindowCocoa(int window, void* event_manager);

void* getNdWindowCocoa(int window);

#endif
