#ifndef ND_WINDOW_COCOA_H
#define ND_WINDOW_COCOA_H

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

#import "event_manager_interface.h"
#import "WindowDelegate.h"
#import "View.h"

@interface ndWindow : NSObject

@property (atomic, strong, nonnull) NSWindow* window;
@property (atomic, strong, nonnull) WindowDelegate* window_delegate;
@property (atomic, strong, nonnull) View* view;
@property (atomic, strong, nonnull) EventManagerInterface* event_mananger_interface;

- (nonnull instancetype) initWithFrame:(NSRect)frame 
                                 title:(nonnull NSString*)title;

@end

#endif
