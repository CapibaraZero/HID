/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw or https://capibarazero.github.io/).
 * Adapted from https://gist.github.com/manuelbl/66f059effc8a7be148adb1f104666467
 * Heavily refactored, cleaned up code and added support for mouse
 * Copyright (c) 2019 Manuel Bl (https://github.com/manuelbl)
 * Copyright (c) 2023 Andrea Canale.
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 */

#include "BLEMouse.hpp"
#include "id.h"

BLECharacteristic* mouse;

BLEMouse::BLEMouse(BLEHIDDevice *hid)
{
    mouse = hid->inputReport(MOUSE_ID); // Mouse report ID
}

BLEMouse::~BLEMouse()
{
}

// From https://github.com/blackketter/ESP32-BLE-Combo/blob/master/BleComboMouse.cpp
void BLEMouse::move(int x, int y, int wheel, int hwheel)
{
    uint8_t msg[5];
    msg[0] = 0;
    msg[1] = x;
    msg[2] = y;
    msg[3] = wheel;
    msg[4] = hwheel;
    mouse->setValue(msg, sizeof(msg));
    mouse->notify();
}

void BLEMouse::move(MouseButton btn, int x, int y, int wheel, int hwheel)
{
    uint8_t msg[5];
    msg[0] = btn;
    msg[1] = x;
    msg[2] = y;
    msg[3] = wheel;
    msg[4] = hwheel;
    mouse->setValue(msg, sizeof(msg));
    mouse->notify();
}

void BLEMouse::move(int btn, int x, int y, int wheel, int hwheel)
{
    uint8_t msg[5];
    msg[0] = btn;
    msg[1] = x;
    msg[2] = y;
    msg[3] = wheel;
    msg[4] = hwheel;
    mouse->setValue(msg, sizeof(msg));
    mouse->notify();
}

void BLEMouse::click(MouseButton type) {
    move(type, 0, 0, 0, 0);
    move(0, 0, 0, 0);
    clicked_btn = MOUSE_NULL;
}

void BLEMouse::release(MouseButton type) {
    move(clicked_btn & ~type, 0, 0, 0);
}

void BLEMouse::press(MouseButton type) {
    move(clicked_btn | type, 0, 0, 0);
}