/*
 * This file is part of the Capibara zero project(https://capibarazero.github.io/).
 * Copyright (c) 2023 Andrea Canale.
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

#ifndef HID_H
#define HID_H

#include "USB.h"
#include "USBHIDKeyboard.h"
#include "USBHIDMouse.h"

class USBHid
{
private:
  USBHIDKeyboard Keyboard;
  USBHIDMouse Mouse;

public:
  USBHid(/* args */);
  ~USBHid();

  void print_char(char char_to_print);

  void print_string(std::string string_to_print);

  void mouse_click();

  void mouse_set_coordinate(int x, int y);

  void mouse_set_coordinate(int x, int y, int wheel_pos);
  void mouse_set_coordinate(int x, int y, int wheel_pos, int pan);
};
#endif
