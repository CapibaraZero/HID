/*
 * This file is part of the Capibara zero
 * project(https://capibarazero.github.io/). Copyright (c) 2023 Andrea Canale.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#if CONFIG_TINYUSB_HID_ENABLED
#ifndef HID_H
#define HID_H

#include "USB.h"
#include "USBHIDKeyboard.h"
#include "USBHIDMouse.h"
#include <string>

#include "Arduino.h"

typedef enum KeyboardLayout{
  de_DE,
  en_US,
  es_ES,
  fr_FR,
  it_IT,
  pt_PT,
  sv_SE,
  da_DK,
  hu_HU,
  pt_BR,
} KeyboardLayout;

KeyboardLayout string_to_enum(const char *layout);
class USBHid {
 private:
  USBHIDKeyboard Keyboard;
  USBHIDMouse Mouse;
  void initialize_hid() {
    USB.begin();
    Keyboard.begin();
    Mouse.begin();
    initialized = true;
  }
  int jitter_max = 20;
  bool jitter_enabled = false;
  bool initialized = false;
 public:
  USBHid(/* args */);
  ~USBHid();

  void print_char(char char_to_print);

  void print_string(std::string string_to_print);

  void mouse_click();

  void mouse_set_coordinate(int x, int y);

  void mouse_set_coordinate(int x, int y, int wheel_pos);
  void mouse_set_coordinate(int x, int y, int wheel_pos, int pan);
  void press(uint8_t key) { Keyboard.press(key); }
  void press_raw(uint8_t key) {
    Keyboard.pressRaw(key);
  }
  void release(uint8_t key) { Keyboard.release(key); }
  void release_all() { Keyboard.releaseAll(); }
  void begin(KeyboardLayout layout = en_US);
  void begin(const char *layout);
  void end();
  void set_jitter_status(bool status) { jitter_enabled = status; }
  void set_jitter_level(int level) { jitter_max = level; }
};
#endif
#endif