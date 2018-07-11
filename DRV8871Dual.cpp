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

void DRV8871Dual::drive (byte speed, byte direction)
{
  _motor1->drive(speed, direction, 0);
  _motor2->drive(speed, direction, 0);
}

void DRV8871Dual::turn (byte speed, byte direction)
{
  if (direction == TURN_LEFT)
  {
    _motor1->drive(speed,_motor1->DIRECTION_FORWARD, 0);
    _motor2->drive(speed,_motor1->DIRECTION_BACKWARD, 0);
  }
  else if (direction == TURN_RIGHT)
  {
    _motor1->drive(speed,_motor1->DIRECTION_BACKWARD, 0);
    _motor2->drive(speed,_motor1->DIRECTION_FORWARD, 0);
  }
}

void DRV8871Dual::breakdown (byte targetSpeed)
{
  _motor1->breakdown(targetSpeed, 0);
  _motor2->breakdown(targetSpeed, 0);
}