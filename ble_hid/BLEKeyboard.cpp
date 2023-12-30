/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw or https://capibarazero.github.io/).
 * Adapted from https://gist.github.com/manuelbl/66f059effc8a7be148adb1f104666467
 * Heavily refactored, cleaned up code and added support for mouse
 * Copyright (c) 2019 Manuel Bl (https://github.com/manuelbl)
 * Copyright (c) 2023 Andrea Canale.
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 */

#include "BLEKeyboard.hpp"
#include "HIDTypes.h"
#include "HIDKeyboardTypes.h"
#include "id.h"
#include "report.h"

#define US_KEYBOARD 1 // US Layout

BLECharacteristic* keyboard;

BLEKeyboard::BLEKeyboard(BLEHIDDevice *hid)
{
    keyboard = hid->inputReport(KEYBOARD_ID); // Keyboard report ID
}

BLEKeyboard::~BLEKeyboard()
{
}

void BLEKeyboard::type(const char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {

        // translate character to key combination
        uint8_t val = (uint8_t)str[i];
        if (val > KEYMAP_SIZE)
            continue; // character not available on keyboard - skip
        KEYMAP map = keymap[val];

        // create input report
        InputReport report = {
            .modifiers = map.modifier,
            .reserved = 0,
            .pressedKeys = {
                map.usage,
                0, 0, 0, 0, 0}};

        // send the input report
        keyboard->setValue((uint8_t *)&report, sizeof(report));
        keyboard->notify();

        delay(5);

        // release all keys between two characters; otherwise two identical
        // consecutive characters are treated as just one key press
        keyboard->setValue((uint8_t *)&NO_KEY_PRESSED, sizeof(NO_KEY_PRESSED));
        keyboard->notify();

        delay(5);
    }
}
