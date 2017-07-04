#import <Cordova/CDVPlugin.h>

@interface MiPlugin : CDVPlugin {
}

// Encabezados de las funciones del plugin
- (void) saludar:(CDVInvokedUrlCommand*)command;

@end
