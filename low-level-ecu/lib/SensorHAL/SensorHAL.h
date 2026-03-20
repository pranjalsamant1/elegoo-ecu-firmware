#ifndef SENSOR_HAL_H
#define SENSOR_HAL_H

#include <Arduino.h>

// Ultrasonic sensor pins — Elegoo V4.0
#define TRIG_PIN  A0
#define ECHO_PIN   2   // Must be interrupt-capable pin

// IR line tracking sensor pins
#define IR_LEFT    A2
#define IR_MIDDLE  A1
#define IR_RIGHT   A3

// MPU6050 uses I2C — pins A4 (SDA) and A5 (SCL) — no defines needed

class SensorHAL {
public:
    void init();

    // Ultrasonic
    float getDistance();        // Returns distance in cm

    // IR line sensors
    bool irLeft();              // true = dark surface detected
    bool irMiddle();
    bool irRight();
    bool cliffDetected();       // true = all 3 sensors see drop

    // Raw analog reads (for debugging)
    int irLeftRaw()   { return analogRead(IR_LEFT);   }
    int irMiddleRaw() { return analogRead(IR_MIDDLE); }
    int irRightRaw()  { return analogRead(IR_RIGHT);  }

private:
    static volatile long _echoDuration;
    static void _echoISR();     // Interrupt service routine
};

#endif
