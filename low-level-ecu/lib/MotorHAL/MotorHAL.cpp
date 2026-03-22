#include "MotorHAL.h"

void MotorHAL::init() {
    pinMode(MOTOR_LEFT_A,  OUTPUT);
    pinMode(MOTOR_LEFT_B,  OUTPUT);
    pinMode(MOTOR_RIGHT_A, OUTPUT);
    pinMode(MOTOR_RIGHT_B, OUTPUT);
    stop();
}

// DRV8835 in IN/IN mode:
// Speed > 0: A=PWM, B=0 (forward)
// Speed < 0: A=0, B=PWM (backward)
// Speed = 0: A=0, B=0 (coast)
void MotorHAL::_setMotor(int pinA, int pinB, int speed) {
    speed = constrain(speed, -255, 255);
    if (speed > 0) {
        analogWrite(pinA, speed);
        analogWrite(pinB, 0);
    } else if (speed < 0) {
        analogWrite(pinA, 0);
        analogWrite(pinB, -speed);
    } else {
        analogWrite(pinA, 0);
        analogWrite(pinB, 0);
    }
}

void MotorHAL::setLeft(int speed)   { _setMotor(MOTOR_LEFT_A,  MOTOR_LEFT_B,  speed); }
void MotorHAL::setRight(int speed)  { _setMotor(MOTOR_RIGHT_A, MOTOR_RIGHT_B, speed); }
void MotorHAL::stop()               { setLeft(0); setRight(0); }
void MotorHAL::forward(int speed)   { setLeft(speed);  setRight(speed); }
void MotorHAL::backward(int speed)  { setLeft(-speed); setRight(-speed); }
void MotorHAL::turnLeft(int speed)  { setLeft(-speed); setRight(speed); }
void MotorHAL::turnRight(int speed) { setLeft(speed);  setRight(-speed); }
