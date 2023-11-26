#include <Arduino.h>
#include "hid.hpp"

Hid hid = Hid();

void setup()
{
    hid.print_string("Hello world!");
    hid.mouse_click();
}

void loop()
{
}