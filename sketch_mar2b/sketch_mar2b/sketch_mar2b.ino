#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);


void setup() {
  pinMode(8, INPUT);
  AFMS.begin();
  pinMode(9, INPUT);

}

void loop() {
    if (digitalRead(8) == HIGH) {
      myMotor1->setSpeed(255);
      myMotor1->run(FORWARD);
      myMotor2->setSpeed(255);
      myMotor2->run(FORWARD);

    } else if (digitalRead(9) == HIGH) {
      myMotor1->setSpeed(255);
      myMotor1->run(BACKWARD);
      myMotor2->setSpeed(255);
      myMotor2->run(BACKWARD);
    } else {
      myMotor1->setSpeed(255);
      myMotor1->run(RELEASE);
      myMotor2->setSpeed(255);
      myMotor2->run(RELEASE);

    }

}