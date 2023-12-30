#ifndef REPORT_H
#define REPORT_H

// Message (report) sent when a key is pressed or released
typedef struct
{
    uint8_t modifiers;      // bitmask: CTRL = 1, SHIFT = 2, ALT = 4
    uint8_t reserved;       // must be 0
    uint8_t pressedKeys[6]; // up to six concurrenlty pressed keys
} InputReport;

#endif