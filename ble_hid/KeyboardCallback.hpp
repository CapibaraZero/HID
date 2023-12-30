#ifndef BLE_KEYBOARD_CALLBACKS
#define BLE_KEYBOARD_CALLBACKS

#include "BLEDevice.h"
#include "BLEHIDDevice.h"

/*
 * Callbacks related to BLE connection
 */
class BleKeyboardCallbacks : public BLEServerCallbacks {
    bool device_connected = false;
    void onConnect(BLEServer* server);
    void onDisconnect(BLEServer* server);

public:
    inline bool is_device_connected() { return device_connected; }
};

#endif