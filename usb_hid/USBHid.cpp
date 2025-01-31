#if CONFIG_TINYUSB_HID_ENABLED
#include "USBHid.hpp"
#include <string>

#include "Arduino.h"

USBHid::USBHid() {};
USBHid::~USBHid() {
  Keyboard.end();
  Mouse.end();
};

void USBHid::begin(KeyboardLayout layout) {
  USB.begin();
  switch (layout) {
  case de_DE:
    Keyboard.begin(KeyboardLayout_de_DE);
    break;
  case es_ES:
    Keyboard.begin(KeyboardLayout_es_ES);
    break;
  case fr_FR:
    Keyboard.begin(KeyboardLayout_fr_FR);
    break;
  case it_IT:
    Keyboard.begin(KeyboardLayout_it_IT);
    break;
  case pt_PT:
    Keyboard.begin(KeyboardLayout_pt_PT);
    break;
  case pt_BR:
    Keyboard.begin(KeyboardLayout_pt_BR);
    break;
  case sv_SE:
    Keyboard.begin(KeyboardLayout_sv_SE);
    break;
  case da_DK:
    Keyboard.begin(KeyboardLayout_da_DK);
    break;
  case hu_HU:
    Keyboard.begin(KeyboardLayout_hu_HU);
    break;
  default:  // en_US and others
    Keyboard.begin();
    break;
  }
  Mouse.begin();
  initialized = true;
}

void USBHid::begin(const char *layout) {
  USB.begin();
  
  if(strcmp("de_DE", layout) == 0)
    Keyboard.begin(KeyboardLayout_de_DE);
  else if(strcmp("es_ES", layout) == 0)
    Keyboard.begin(KeyboardLayout_es_ES);
  else if(strcmp("fr_FR", layout) == 0)
    Keyboard.begin(KeyboardLayout_fr_FR);
  else if(strcmp("it_IT", layout) == 0)
    Keyboard.begin(KeyboardLayout_it_IT);
  else if(strcmp("pt_PT", layout) == 0)
    Keyboard.begin(KeyboardLayout_pt_PT);
  else if(strcmp("pt_BR", layout) == 0)
    Keyboard.begin(KeyboardLayout_pt_BR);
  else if(strcmp("sv_SE", layout) == 0)
    Keyboard.begin(KeyboardLayout_sv_SE);
  else if(strcmp("da_DK", layout) == 0)
    Keyboard.begin(KeyboardLayout_da_DK);
  else if(strcmp("hu_HU", layout) == 0)
    Keyboard.begin(KeyboardLayout_hu_HU);
  else  // en_US and others
    Keyboard.begin();
  
  Mouse.begin();
  initialized = true;
}

void USBHid::end() {
  Keyboard.end();
  Mouse.end();
}
void USBHid::print_char(char char_to_print) { 
  if(!initialized)
    initialize_hid();
  Keyboard.print(char_to_print); 
}

void USBHid::print_string(std::string string_to_print) {
  if(!initialized)
    initialize_hid();
  for (char c : string_to_print) {
    Keyboard.print(c);
    if (jitter_enabled) delay(random(0, jitter_max));
  }
}

void USBHid::mouse_click() { 
  if(!initialized)
    initialize_hid();
  Mouse.click(); 
}

void USBHid::mouse_set_coordinate(int x, int y) { 
  if(!initialized)
    initialize_hid();
  Mouse.move(x, y); 
}

void USBHid::mouse_set_coordinate(int x, int y, int wheel_pos) {
  if(!initialized)
    initialize_hid();
  Mouse.move(x, y, wheel_pos);
}

void USBHid::mouse_set_coordinate(int x, int y, int wheel_pos, int pan) {
  if(!initialized)
    initialize_hid();
  Mouse.move(x, y, wheel_pos, pan);
}
#endif