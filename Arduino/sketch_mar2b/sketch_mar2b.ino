#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *rightMotor = AFMS.getMotor(1);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);


void setup() {
  AFMS.begin();
  
  
}

void loop() {
  // run motors forward
  rightMotor->setSpeed(150); // you can set speed from 0(stopped) to 255(max)
  rightMotor->run(FORWARD);
  leftMotor->setSpeed(150); 
  leftMotor->run(FORWARD);
  delay(2000);

  // run motors backward
  rightMotor->setSpeed(150); 
  rightMotor->run(BACKWARD);
  leftMotor->setSpeed(150); 
  leftMotor->run(BACKWARD);
  delay(2000);

  rightMotor->run(RELEASE);
  leftMotor->run(RELEASE);
  delay(2000);
}
