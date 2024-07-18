#include "logger.h"
#include "test_success.h"
#import "WindowDelegate.h"

@implementation WindowDelegate

- (instancetype) init {
    self = [super init];
    if (self != nil) {
        [self setNdclose_window:NO];
        ndLog(SUC, APP_InitWindowDelegate);
    }

    return self;
}

- (void) windowWillClose:(NSNotification *)notification {
    ndLog(LOG, "windowWillClose");
    [self setNdclose_window:YES];
}

@end
