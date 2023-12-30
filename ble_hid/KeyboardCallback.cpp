/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw or https://capibarazero.github.io/).
 * Adapted from https://gist.github.com/manuelbl/66f059effc8a7be148adb1f104666467
 * Heavily refactored, cleaned up code and added support for mouse
 * Copyright (c) 2019 Manuel Bl (https://github.com/manuelbl)
 * Copyright (c) 2023 Andrea Canale.
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 */

#include "BLEDevice.h"
#include "BLEHIDDevice.h"
#include "KeyboardCallback.hpp"
#include "BLEKeyboard.hpp"
#include "BLEMouse.hpp"

void BleKeyboardCallbacks::onConnect(BLEServer *server)
{
    // // Allow notifications for characteristics
    BLE2902 *cccDesc = (BLE2902 *)keyboard->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
    cccDesc->setNotifications(true);

    cccDesc = (BLE2902 *)mouse->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
    cccDesc->setNotifications(true);
    device_connected = true;
}

void BleKeyboardCallbacks::onDisconnect(BLEServer *server)
{
    // // Disallow notifications for characteristics
    BLE2902 *cccDesc = (BLE2902 *)keyboard->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
    cccDesc->setNotifications(false);
    
    cccDesc = (BLE2902 *)mouse->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
    cccDesc->setNotifications(false);
    device_connected = false;
}