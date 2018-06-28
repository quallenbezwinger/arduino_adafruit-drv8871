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

void DRV8871Dual::drive (byte speed, byte direction, int acceleration)
{
  _motor1->drive(speed, direction, acceleration);
  _motor2->drive(speed, direction, acceleration);
}

void DRV8871Dual::turn (byte speed, byte direction, int acceleration)
{
  if (direction == TURN_LEFT)
  {
    _motor1->drive(speed,_motor1->DIRECTION_FORWARD, acceleration);
    _motor2->drive(speed,_motor1->DIRECTION_BACKWARD, acceleration);
  }
  else if (direction == TURN_RIGHT)
  {
    _motor1->drive(speed,_motor1->DIRECTION_BACKWARD, acceleration);
    _motor2->drive(speed,_motor1->DIRECTION_FORWARD, acceleration);
  }
}

void DRV8871Dual::breakdown (byte targetSpeed, int acceleration)
{
  _motor1->breakdown(targetSpeed, acceleration);
  _motor2->breakdown(targetSpeed, acceleration);
}