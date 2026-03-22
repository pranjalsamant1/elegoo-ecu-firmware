#include "SensorHAL.h"

void SensorHAL::init() {
    // Ultrasonic
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(TRIG_PIN, LOW);

    // IR line tracking
    pinMode(IR_LEFT,   INPUT);
    pinMode(IR_MIDDLE, INPUT);
    pinMode(IR_RIGHT,  INPUT);
}

float SensorHAL::getDistance() {
    // Send 10us trigger pulse
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // pulseIn blocks but echo pin 12 is not interrupt-capable on UNO
    long duration = pulseIn(ECHO_PIN, HIGH, 30000);
    if (duration == 0) return -1.0f;
    return (duration * 0.0343f) / 2.0f;
}

// From schematic: IR sensors on P7 — A2=Left, A1=Middle, A0=Right
// HIGH = no surface / light surface
// LOW  = dark surface / line detected
bool SensorHAL::irLeft()   { return digitalRead(IR_LEFT)   == LOW; }
bool SensorHAL::irMiddle() { return digitalRead(IR_MIDDLE) == LOW; }
bool SensorHAL::irRight()  { return digitalRead(IR_RIGHT)  == LOW; }

// Cliff = all sensors read HIGH (no dark surface under any sensor)
bool SensorHAL::cliffDetected() {
    return (digitalRead(IR_LEFT)   == HIGH) &&
           (digitalRead(IR_MIDDLE) == HIGH) &&
           (digitalRead(IR_RIGHT)  == HIGH);
}
