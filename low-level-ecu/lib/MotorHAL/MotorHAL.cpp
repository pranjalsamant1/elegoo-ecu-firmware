#include "MotorHAL.h"

void MotorHAL::init() {
    pinMode(MOTOR_LEFT_PWM,  OUTPUT);
    pinMode(MOTOR_LEFT_IN1,  OUTPUT);
    pinMode(MOTOR_LEFT_IN2,  OUTPUT);
    pinMode(MOTOR_RIGHT_PWM, OUTPUT);
    pinMode(MOTOR_RIGHT_IN1, OUTPUT);
    pinMode(MOTOR_RIGHT_IN2, OUTPUT);
    stop();
}

void MotorHAL::_setMotor(int pwmPin, int in1, int in2, int speed) {
    speed = constrain(speed, -255, 255);
    if (speed > 0) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else if (speed < 0) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
    }
    analogWrite(pwmPin, abs(speed));
}

void MotorHAL::setLeft(int speed)   { _setMotor(MOTOR_LEFT_PWM,  MOTOR_LEFT_IN1,  MOTOR_LEFT_IN2,  speed); }
void MotorHAL::setRight(int speed)  { _setMotor(MOTOR_RIGHT_PWM, MOTOR_RIGHT_IN1, MOTOR_RIGHT_IN2, speed); }
void MotorHAL::stop()               { setLeft(0); setRight(0); }
void MotorHAL::forward(int speed)   { setLeft(speed);  setRight(speed); }
void MotorHAL::backward(int speed)  { setLeft(-speed); setRight(-speed); }
void MotorHAL::turnLeft(int speed)  { setLeft(-speed); setRight(speed); }
void MotorHAL::turnRight(int speed) { setLeft(speed);  setRight(-speed); }
