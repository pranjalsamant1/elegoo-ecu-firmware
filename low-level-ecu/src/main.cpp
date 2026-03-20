#include <Arduino.h>
#include "MotorHAL.h"
#include "SensorHAL.h"
#include "MPU6050.h"

MotorHAL  motors;
SensorHAL sensors;
MPU6050   imu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
    Serial.begin(115200);
    Wire.begin();

    motors.init();
    sensors.init();

    imu.initialize();

    if (imu.testConnection()) {
        Serial.println("MPU6050 connected OK");
    } else {
        Serial.println("MPU6050 connection FAILED");
    }

    Serial.println("=== Low-Level ECU Booting ===");
    Serial.println("Format: dist | IRl IRm IRr | cliff | ax ay az | gx gy gz");
}

void loop() {
    // Read ultrasonic + IR
    float dist = sensors.getDistance();
    bool cliff = sensors.cliffDetected();

    // Read IMU raw data
    imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Print everything on one line
    Serial.print(dist);        Serial.print(" cm | ");
    Serial.print(sensors.irLeft());   Serial.print(" ");
    Serial.print(sensors.irMiddle()); Serial.print(" ");
    Serial.print(sensors.irRight());  Serial.print(" | ");
    Serial.print(cliff ? "CLIFF" : "ok"); Serial.print(" | ");
    Serial.print(ax); Serial.print(" ");
    Serial.print(ay); Serial.print(" ");
    Serial.print(az); Serial.print(" | ");
    Serial.print(gx); Serial.print(" ");
    Serial.print(gy); Serial.print(" ");
    Serial.println(gz);

    delay(100); // 10Hz for now
}
