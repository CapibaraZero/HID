#include "USBHid.hpp"

#include "Arduino.h"

USBHid::USBHid(){};
USBHid::~USBHid() {
    Keyboard.end();
    Mouse.end();
};

void USBHid::begin() {
    USB.begin();
    Keyboard.begin();
    Mouse.begin();
}

void USBHid::end() {
  Keyboard.end();
  Mouse.end();
}
void USBHid::print_char(char char_to_print) { Keyboard.print(char_to_print); }

void USBHid::print_string(std::string string_to_print) {
    for (char c : string_to_print) {
        Keyboard.print(c);
        if(jitter_enabled)
            delay(random(0, jitter_max));
    }
    
}

void USBHid::mouse_click() { Mouse.click(); }

void USBHid::mouse_set_coordinate(int x, int y) { Mouse.move(x, y); }

void USBHid::mouse_set_coordinate(int x, int y, int wheel_pos) {
    Mouse.move(x, y, wheel_pos);
}

void USBHid::mouse_set_coordinate(int x, int y, int wheel_pos, int pan) {
    Mouse.move(x, y, wheel_pos, pan);
}