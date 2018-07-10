/*
  DRV8871.cpp - Library for interacting with DRV8871
  Created by Dirk Köhler
*/

#include "Arduino.h"
#include "DRV8871_MotorConfig.h"

DRV8871_MotorConfig::DRV8871_MotorConfig(byte motorIN1Pin, byte motorIN2Pin)
{
  _motorIN1Pin = motorIN1Pin;
  _motorIN2Pin = motorIN2Pin;
  pinMode(_motorIN1Pin, OUTPUT);
  pinMode(_motorIN2Pin, OUTPUT); 
}

byte DRV8871_MotorConfig::getMotorIN1Pin()
{
  return _motorIN1Pin;
}

byte DRV8871_MotorConfig::getMotorIN2Pin()
{
  return _motorIN2Pin;
}