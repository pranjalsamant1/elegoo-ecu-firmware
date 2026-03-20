#ifndef MOTOR_HAL_H
#define MOTOR_HAL_H

#include <Arduino.h>

// Elegoo V4.0 TB6612 motor driver pin definitions
#define MOTOR_LEFT_PWM    5
#define MOTOR_LEFT_IN1    7
#define MOTOR_LEFT_IN2    8
#define MOTOR_RIGHT_PWM   6
#define MOTOR_RIGHT_IN1   9
#define MOTOR_RIGHT_IN2  10

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
    void _setMotor(int pwmPin, int in1, int in2, int speed);
};

#endif
