/*
  DRV8871.cpp - Library for interacting with DRV8871
  Created by Dirk Köhler
*/

#include "Arduino.h"
#include "DRV8871.h"

DRV8871::DRV8871(byte motorIN1Pin, byte motorIN2Pin)
{
  byte _motorIN1Pin = motorIN1Pin;
  byte _motorIN2Pin = motorIN2Pin;
  pinMode(motorIN1Pin, OUTPUT);
  pinMode(motorIN2Pin, OUTPUT); 
  _currentDirection = DIRECTION_NONE;
}

void DRV8871::accelerate(byte targetSpeed, byte direction)
{
  if (direction == DIRECTION_FORWARD && _currentDirection == DIRECTION_NONE)
  {
    rampUpForward(targetSpeed);
  } else if (direction == DIRECTION_FORWARD && _currentDirection == DIRECTION_BACKWARD)
  {
    rampDownBackward(0);
    rampUpForward(targetSpeed);
  } else if (direction == DIRECTION_BACKWARD && _currentDirection == DIRECTION_BACKWARD)
  {
    rampUpBackward(targetSpeed);
  } else if (direction == DIRECTION_BACKWARD && _currentDirection == DIRECTION_FORWARD)
  {
    rampDownForward(0);
    rampUpBackward(0);
  }
}

void DRV8871::breakdown(byte targetSpeed = 0)
{
  if (_currentDirection == DIRECTION_FORWARD)
  {
    rampDownForward(targetSpeed);
  } else
  {
    rampDownBackward(targetSpeed);
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

void DRV8871::rampUpForward(byte targetSpeed)
{
  _currentDirection = DIRECTION_FORWARD;
  digitalWrite(_motorIN1Pin, LOW);
  for (int i=_currentSpeed; i<targetSpeed; i++)
  {
    Serial.println("i");
    Serial.println(i);
    analogWrite(_motorIN2Pin, i);
    _currentSpeed = i;
    delay(ACCELERATION_DELAY_MS);
  }
}

void DRV8871::rampDownForward(byte targetSpeed)
{
  _currentDirection = DIRECTION_FORWARD;
  digitalWrite(_motorIN1Pin, LOW);
  for (int i=_currentSpeed; i>=targetSpeed; i--)
  {
    analogWrite(_motorIN2Pin, i);
    _currentSpeed = i;
    delay(ACCELERATION_DELAY_MS);
  }
}

void DRV8871::rampUpBackward(byte targetSpeed)
{
   _currentDirection = DIRECTION_BACKWARD;
  digitalWrite(_motorIN2Pin, LOW);
  for (int i=_currentSpeed; i<targetSpeed; i++)
  {
    analogWrite(_motorIN1Pin, i);
    _currentSpeed = i;
    delay(ACCELERATION_DELAY_MS);
  }
}

void DRV8871::rampDownBackward(byte targetSpeed)
{
   _currentDirection = DIRECTION_BACKWARD;
  digitalWrite(_motorIN2Pin, LOW);
  for (int i=_currentSpeed; i>=targetSpeed; i--)
  {
    analogWrite(_motorIN1Pin, i);
    _currentSpeed = i;
    delay(ACCELERATION_DELAY_MS);
  }
}
