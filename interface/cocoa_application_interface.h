#ifndef COCOA_APPLICATION_INTERFACE_H
#define COCOA_APPLICATION_INTERFACE_H

// ================ Cocoa Application ================
void initCocoa();
void pollEventsCocoa();


// ================ Windows ================
void initWindowBlockArrayCocoa();
int  createWindowCocoa(int width, int height, const char* title);

void* getNdWindowCocoa(int window);

#endif
