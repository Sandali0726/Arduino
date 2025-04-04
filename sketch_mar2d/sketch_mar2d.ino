#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);


void setup() {
  pinMode(8, INPUT);
  AFMS.begin();
  pinMode(9, INPUT);

}

void loop() {
    if (digitalRead(8) == HIGH) {
      myMotor1->setSpeed(255);
      myMotor1->run(FORWARD);
      myMotor1->setSpeed(255);
      myMotor1->run(FORWARD);

    } else if (digitalRead(9) == HIGH) {
      myMotor1->setSpeed(255);
      myMotor1->run(BACKWARD);
      myMotor1->setSpeed(255);
      myMotor1->run(BACKWARD);
    } else {
      myMotor1->setSpeed(255);
      myMotor1->run(RELEASE);
      myMotor1->setSpeed(255);
      myMotor1->run(RELEASE);

    }

}