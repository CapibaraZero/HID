#include <Arduino.h>
#include "usb_hid/USBHid.hpp"

USBHid hid = USBHid();

void setup()
{
    hid.print_string("Hello world!");
    hid.mouse_click();
}

void loop()
{
}