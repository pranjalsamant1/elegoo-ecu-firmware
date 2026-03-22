#ifndef MOTOR_HAL_H
#define MOTOR_HAL_H

#include <Arduino.h>

// === PINS FROM ELEGOO V4.0 SCHEMATIC (DRV8835) ===
// DRV8835: AO1/AO2 = Left motor, BO1/BO2 = Right motor
// AOUT1 = pin 9, AOUT2 = pin 6 (via AIN1/AIN2 PWM)
// BOUT1 = pin 10, BOUT2 = pin 5

#define MOTOR_LEFT_A    9    // Left motor PWM A
#define MOTOR_LEFT_B    6    // Left motor PWM B
#define MOTOR_RIGHT_A   10   // Right motor PWM A
#define MOTOR_RIGHT_B   5    // Right motor PWM B

class MotorHAL {
public:
    void init();
    void setLeft(int speed);    // -255 to +255
    void setRight(int speed);   // -255 to +255
    void stop();
    void forward(int speed);
    void backward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);

private:
    void _setMotor(int pinA, int pinB, int speed);
};

#endif
