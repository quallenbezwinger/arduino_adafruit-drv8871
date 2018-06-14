/*
  DRV8871.cpp - Library for interacting with DRV8871
  Created by Dirk.
*/

#include "Arduino.h"
#include "DRV8871.h"

DRV8871::DRV8871(byte motorIN1Pin, byte motorIN2Pin)
{
  byte _motorIN1Pin = motorIN1Pin;
  byte _motorIN2Pin = motorIN2Pin;
  pinMode(motorIN1Pin, OUTPUT);
  pinMode(motorIN2Pin, OUTPUT);  
}

//start driving forward
void DRV8871::accForward(byte targetSpeed)
{
  if (targetSpeed <= 100 && targetSpeed > 0)
  {
    digitalWrite(_motorIN1Pin, LOW);
    for (int i=0; i<255; i++) {
      analogWrite(_motorIN2Pin, i*(targetSpeed/100));
      delay(10);
    }
  }
}
