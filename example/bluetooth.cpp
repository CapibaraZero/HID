#include <Arduino.h>
#include "ble_hid/BLEHid.hpp"

void setup()
{
  Serial.begin(115200);
  BLEHid ble_hid = BLEHid();

  for (;;)
  {
    if (ble_hid.is_device_connected())
    {
      Serial.println("Device connected. Typing in progress");
      ble_hid.get_keyboard().type("Hello world!");
      ble_hid.get_mouse().move(200, 200, 4, 4);
      ble_hid.get_mouse().click();
    }
    else
    {
      Serial.println("Device not connected");
    }
    delay(10000);
  }
}

void loop()
{
}