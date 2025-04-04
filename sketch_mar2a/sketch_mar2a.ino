/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.15.01 or later version;
     - for iOS 1.12.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL

#include <SoftwareSerial.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 53 bytes
  { 255,2,0,0,0,46,0,19,0,0,0,0,31,1,106,200,1,1,2,0,
  1,44,13,24,24,0,203,31,102,111,114,119,97,114,100,0,1,41,162,24,
  24,0,203,31,98,97,99,107,119,97,114,100,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_01; // =1 if button pressed, else =0
  uint8_t button_02; // =1 if button pressed, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);

#define PIN_BUTTON_01 8
#define PIN_BUTTON_02 9


void setup() 
{
  RemoteXY_Init (); 
  AFMS.begin();
  pinMode (PIN_BUTTON_01, OUTPUT);
  pinMode (PIN_BUTTON_02, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_BUTTON_01, (RemoteXY.button_01==0)?LOW:HIGH);
  digitalWrite(PIN_BUTTON_02, (RemoteXY.button_02==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 
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