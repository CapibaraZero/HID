#include "USB.h"
#include "USBHIDKeyboard.h"
#include "USBHIDMouse.h"

class Hid
{
private:
  USBHIDKeyboard Keyboard;
  USBHIDMouse Mouse;

public:
  Hid(/* args */);
  ~Hid();

  void print_char(char char_to_print);

  void print_string(std::string string_to_print);

  void mouse_click();

  void mouse_set_coordinate(int x, int y);

  void mouse_set_coordinate(int x, int y, int wheel_pos);
  void mouse_set_coordinate(int x, int y, int wheel_pos, int pan);
};