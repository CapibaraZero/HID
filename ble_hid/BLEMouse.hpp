/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw or https://capibarazero.github.io/).
 * Adapted from https://gist.github.com/manuelbl/66f059effc8a7be148adb1f104666467
 * Heavily refactored, cleaned up code and added support for mouse
 * Copyright (c) 2019 Manuel Bl (https://github.com/manuelbl)
 * Copyright (c) 2023 Andrea Canale.
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 */

#ifndef BLEMOUSE_H
#define BLEMOUSE_H

#include "BLEDevice.h"
#include "BLEHIDDevice.h"

/* Mouse button */
enum MouseButton {
  MOUSE_NULL = 0, // No button selected
  MOUSE_LEFT = 1,
  MOUSE_RIGHT = 2,
  MOUSE_MIDDLE = 4,
  MOUSE_BACK = 8,
  MOUSE_FORWARD = 16,
  MOUSE_ALL = (MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE)
};

extern BLECharacteristic* mouse;

class BLEMouse
{
private:
    MouseButton clicked_btn = MOUSE_NULL;
    // Internal usage
    void move(int btn, int x, int y, int wheel, int hwheel);
public:
    BLEMouse(BLEHIDDevice *hid);
    ~BLEMouse();


    // Mouse functions

    /// @brief Move mouse and select mouse button
    /// @param btn Mouse button to use
    /// @param x X cordinate
    /// @param y Y cordinate
    /// @param wheel Wheel position
    /// @param hwheel Horizontal wheel position
    void move(MouseButton btn, int x, int y, int wheel = 0, int hwheel = 0);

    /// @brief Move mouse
    /// @param x X cordinate
    /// @param y Y cordinate
    /// @param wheel Wheel position
    /// @param hwheel Horizontal wheel position
    void move(int x, int y, int wheel, int hwheel);
    
    /// @brief Generate a mouse click
    /// @param type MouseButton to use. By default is left
    void click(MouseButton type = MOUSE_LEFT);
    void release(MouseButton type = MOUSE_LEFT);
    void press(MouseButton type = MOUSE_LEFT);
};

#endif