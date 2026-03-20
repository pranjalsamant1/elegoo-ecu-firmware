#include "SensorHAL.h"

// Static member definitions
volatile long SensorHAL::_echoDuration = 0;

void SensorHAL::_echoISR() {
    static unsigned long startTime = 0;
    if (digitalRead(ECHO_PIN) == HIGH) {
        startTime = micros();
    } else {
        _echoDuration = micros() - startTime;
    }
}

void SensorHAL::init() {
    // Ultrasonic
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(ECHO_PIN), _echoISR, CHANGE);

    // IR sensors
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

    // Wait for echo (max 30ms timeout)
    unsigned long timeout = millis();
    while (_echoDuration == 0 && millis() - timeout < 30);

    float distance = (_echoDuration * 0.0343f) / 2.0f;
    _echoDuration = 0;
    return distance;
}

bool SensorHAL::irLeft()   { return digitalRead(IR_LEFT)   == LOW; }
bool SensorHAL::irMiddle() { return digitalRead(IR_MIDDLE) == LOW; }
bool SensorHAL::irRight()  { return digitalRead(IR_RIGHT)  == LOW; }

bool SensorHAL::cliffDetected() {
    // All 3 sensors see no surface = cliff
    return !irLeft() && !irMiddle() && !irRight();
}
