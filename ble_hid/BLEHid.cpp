/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw or https://capibarazero.github.io/).
 * Adapted from https://gist.github.com/manuelbl/66f059effc8a7be148adb1f104666467
 * Heavily refactored, cleaned up code and added support for mouse
 * Copyright (c) 2019 Manuel Bl (https://github.com/manuelbl)
 * Copyright (c) 2023 Andrea Canale.
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 */

#include "BLEHid.hpp"
#include "Arduino.h"
#include "nvs_flash.h"


BLEHid::BLEHid(const char *device_name, const char *manufacturer, int battery_level)
{
    // initialize the device
    BLEDevice::init(device_name);

    // Create BLE server
    create_server();

    // Bonding security
    set_security();

    // Create HIDDevice object
    create_hid_device(manufacturer, battery_level);

    // Start advertising
    start_advertise();
}

BLEHid::~BLEHid()
{
    advertising->stop();
    BLEDevice::deinit(true);
}

void BLEHid::create_server()
{
    server = BLEDevice::createServer();
    server->setCallbacks(keyboard_callbacks);
}

void BLEHid::set_security()
{
    // Security: device requires bonding
    security = new BLESecurity();
    security->setAuthenticationMode(ESP_LE_AUTH_BOND);
}

void BLEHid::start_advertise()
{
    // advertise the services
    advertising = server->getAdvertising();
    advertising->setAppearance(HID_KEYBOARD);   // Device appear as keyboard
    // Some device infos
    advertising->addServiceUUID(hid->hidService()->getUUID());
    advertising->addServiceUUID(hid->deviceInfo()->getUUID());
    advertising->addServiceUUID(hid->batteryService()->getUUID());
    advertising->start();
}

void BLEHid::create_hid_device(const char *manufacturer, int battery_level)
{
    // create an HID device
    hid = new BLEHIDDevice(server);
    keyboard = new BLEKeyboard(hid);
    mouse = new BLEMouse(hid);
    
    // set manufacturer name
    hid->manufacturer()->setValue(manufacturer);
    // set USB vendor and product ID
    hid->pnp(0x02, 0xe502, 0xa111, 0x0210);
    // information about HID device: device is not localized, device can be connected
    hid->hidInfo(0x00, 0x01);

    // set report map
    hid->reportMap((uint8_t *)REPORT_MAP, sizeof(REPORT_MAP));
    hid->startServices();

    // set battery level
    hid->setBatteryLevel(battery_level);
}