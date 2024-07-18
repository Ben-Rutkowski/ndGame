#ifndef ND_WINDOW_COCOA_H
#define ND_WINDOW_COCOA_H

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

#import "WindowDelegate.h"

@interface ndWindow : NSObject
@property (atomic, strong, nonnull) NSWindow* window;
@property (atomic, strong, nonnull) WindowDelegate* window_delegate;

- (nonnull instancetype) initWithFrame:(NSRect)frame 
                                 title:(nonnull NSString*)title;
@end

#endif
