/*
  DRV8871Dual.cpp - Library for interacting with DRV8871Dual
  Created by Dirk Köhler
*/

#include "Arduino.h"
#include "DRV8871Dual.h"
#include "DRV8871.h"

DRV8871Dual::DRV8871Dual(DRV8871* motor1, DRV8871* motor2)
{
  _motor1 = motor1;
  _motor2 = motor2;
}

void DRV8871Dual::accelerate (byte speed, byte direction)
{
  _motor1->accelerate(speed,direction);
  _motor2->accelerate(speed,direction);
}

void DRV8871Dual::turn (byte speed, byte direction)
{
  if (direction == TURN_LEFT)
  {
    _motor1->accelerate(speed,_motor1->DIRECTION_FORWARD);
    _motor2->accelerate(speed,_motor1->DIRECTION_BACKWARD);
  }
  else if (direction == TURN_RIGHT)
  {
    _motor1->accelerate(speed,_motor1->DIRECTION_BACKWARD);
    _motor2->accelerate(speed,_motor1->DIRECTION_FORWARD);
  }
}