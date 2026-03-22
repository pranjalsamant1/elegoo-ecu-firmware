#ifndef SENSOR_HAL_H
#define SENSOR_HAL_H

#include <Arduino.h>

// === PINS FROM ELEGOO V4.0 SCHEMATIC ===
// Ultrasonic (P9 header)
#define TRIG_PIN  13
#define ECHO_PIN  12   // NOT interrupt-capable on UNO — uses pulseIn

// IR line tracking (P7 header)
#define IR_LEFT    A2
#define IR_MIDDLE  A1
#define IR_RIGHT   A0

class SensorHAL {
public:
    void init();
    float getDistance();    // Returns cm, -1 on timeout
    bool irLeft();          // true = dark surface detected
    bool irMiddle();
    bool irRight();
    bool cliffDetected();   // true = all 3 sensors see cliff/drop
};

#endif
