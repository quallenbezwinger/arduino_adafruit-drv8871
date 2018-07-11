/*
  DRV8871.cpp - Library for interacting with DRV8871
  Created by Dirk Köhler
*/

#include "Arduino.h"
#include "DRV8871.h"

DRV8871::DRV8871(byte motorIN1Pin, byte motorIN2Pin)
{
  _motorIN1Pin = motorIN1Pin;
  _motorIN2Pin = motorIN2Pin;
  pinMode(_motorIN1Pin, OUTPUT);
  pinMode(_motorIN2Pin, OUTPUT); 
  _currentDirection = DIRECTION_NONE;
}

void DRV8871::drive(byte targetSpeed, byte direction, int acceleration)
{
  //check if direction and speed is already set to prevent unnecessary execution
  if (direction == _currentDirection && targetSpeed == _currentSpeed)
  {
    return;
  }
  
  if (direction == DIRECTION_FORWARD && _currentDirection == DIRECTION_BACKWARD)
  {
    rampDownBackward(0, acceleration);
    rampUpForward(targetSpeed, acceleration);
  }
  else if (direction == DIRECTION_FORWARD || _currentDirection == DIRECTION_NONE)
  {
    rampUpForward(targetSpeed, acceleration);
  } 
  else if (direction == DIRECTION_BACKWARD && _currentDirection == DIRECTION_FORWARD)
  {
    rampDownForward(0, acceleration);
    rampUpBackward(targetSpeed, acceleration);
  }
  else if (direction == DIRECTION_BACKWARD || _currentDirection == DIRECTION_NONE)
  {
    rampUpBackward(targetSpeed, acceleration);
  }
  //check if spped is 0, if yes direction is set to neutral
  if (_currentSpeed == 0)
  {
    _currentDirection == DIRECTION_NONE;
  }
}

void DRV8871::breakdown(byte targetSpeed, int acceleration)
{
  if (_currentDirection == DIRECTION_FORWARD)
  {
    rampDownForward(targetSpeed, acceleration);
  }
  else
  {
    rampDownBackward(targetSpeed, acceleration);
  }
}

void DRV8871::rampUpForward(byte targetSpeed, int acceleration)
{
  _currentDirection = DIRECTION_FORWARD;
  digitalWrite(_motorIN1Pin, LOW);
  for (int i=_currentSpeed; i<targetSpeed; i++)
  {
    analogWrite(_motorIN2Pin, i);
    _currentSpeed = i;
    delay(acceleration);
  }
}

void DRV8871::rampDownForward(byte targetSpeed, int acceleration)
{
  _currentDirection = DIRECTION_FORWARD;
  digitalWrite(_motorIN1Pin, LOW);
  for (int i=_currentSpeed; i>=targetSpeed; i--)
  {
    analogWrite(_motorIN2Pin, i);
    _currentSpeed = i;
    delay(acceleration);
  }
}

void DRV8871::rampUpBackward(byte targetSpeed, int acceleration)
{
   _currentDirection = DIRECTION_BACKWARD;
  digitalWrite(_motorIN2Pin, LOW);
  for (int i=_currentSpeed; i<targetSpeed; i++)
  {
    analogWrite(_motorIN1Pin, i);
    _currentSpeed = i;
    delay(acceleration);
  }
}

void DRV8871::rampDownBackward(byte targetSpeed, int acceleration)
{
   _currentDirection = DIRECTION_BACKWARD;
  digitalWrite(_motorIN2Pin, LOW);
  for (int i=_currentSpeed; i>=targetSpeed; i--)
  {
    analogWrite(_motorIN1Pin, i);
    _currentSpeed = i;
    delay(acceleration);
  }
}

byte DRV8871::currentSpeed ()
{
  return _currentSpeed;
}

byte DRV8871::currentDirection ()
{
  return _currentDirection;
}