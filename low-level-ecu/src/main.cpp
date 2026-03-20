#include <Arduino.h>
#include "MotorHAL.h"
#include "SensorHAL.h"

MotorHAL  motors;
SensorHAL sensors;

void setup() {
    Serial.begin(115200);
    motors.init();
    sensors.init();
    Serial.println("=== Low-Level ECU Booting ===");
    Serial.println("MotorHAL  : OK");
    Serial.println("SensorHAL : OK");
}

void loop() {
    float dist = sensors.getDistance();

    Serial.print("Distance: ");
    Serial.print(dist);
    Serial.print(" cm | IR L:");
    Serial.print(sensors.irLeft());
    Serial.print(" M:");
    Serial.print(sensors.irMiddle());
    Serial.print(" R:");
    Serial.print(sensors.irRight());
    Serial.print(" | Cliff:");
    Serial.println(sensors.cliffDetected());

    delay(200);
}
