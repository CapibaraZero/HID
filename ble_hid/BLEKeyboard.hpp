/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw or https://capibarazero.github.io/).
 * Adapted from https://gist.github.com/manuelbl/66f059effc8a7be148adb1f104666467
 * Heavily refactored, cleaned up code and added support for mouse
 * Copyright (c) 2019 Manuel Bl (https://github.com/manuelbl)
 * Copyright (c) 2023 Andrea Canale.
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 */

#ifndef BLEKEYBOARD_H
#define BLEKEYBOARD_H

#include "BLEDevice.h"
#include "BLEHIDDevice.h"
#include "Arduino.h"
#include "report.h"

extern BLECharacteristic* keyboard;

class BLEKeyboard
{
private:
    const InputReport NO_KEY_PRESSED = { };

public:
    BLEKeyboard(BLEHIDDevice *hid);
    ~BLEKeyboard();
    void type(const char *str);
};

#endif