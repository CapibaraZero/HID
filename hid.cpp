#include "Arduino.h"
#include "hid.hpp"

Hid::Hid()
{
  USB.begin();
  Keyboard.begin();
  Mouse.begin();
};
Hid::~Hid()
{
  Keyboard.end();
  Mouse.end();
};

void Hid::print_char(char char_to_print)
{
  Keyboard.print(char_to_print);
}

void Hid::print_string(std::string string_to_print)
{
  Keyboard.print(string_to_print.c_str());
}

void Hid::mouse_click()
{
  Mouse.click();
}

void Hid::mouse_set_coordinate(int x, int y)
{
  Mouse.move(x, y);
}

void Hid::mouse_set_coordinate(int x, int y, int wheel_pos)
{
  Mouse.move(x, y, wheel_pos);
}

void Hid::mouse_set_coordinate(int x, int y, int wheel_pos, int pan)
{
  Mouse.move(x, y, wheel_pos, pan);
}