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

void DRV8871::accelerate(byte targetSpeed, byte direction)
{
  if (direction == DIRECTION_FORWARD && _currentDirection == DIRECTION_BACKWARD)
  {
    #ifdef DEBUG
      Serial.println("ramp down backward and then ramp up forward");
    #endif
    rampDownBackward(0);
    rampUpForward(targetSpeed);
  } else if (direction == DIRECTION_FORWARD || _currentDirection == DIRECTION_NONE)
  {
    #ifdef DEBUG
      Serial.println("ramp up forward");
    #endif
    rampUpForward(targetSpeed);
  } 
  else if (direction == DIRECTION_BACKWARD && _currentDirection == DIRECTION_FORWARD)
  {
    #ifdef DEBUG
      Serial.println("ramp down forward and then ramp up backward");
    #endif
    rampDownForward(0);
    rampUpBackward(targetSpeed);
  } else if (direction == DIRECTION_BACKWARD || _currentDirection == DIRECTION_NONE)
  {
    #ifdef DEBUG
      Serial.println("ramp up backward");
    #endif
    rampUpBackward(targetSpeed);
  }
  //check if spped is 0, if yes direction is set to neutral
  if (_currentSpeed == 0)
  {
    _currentDirection == DIRECTION_NONE;
  }
}

void DRV8871::breakdown(byte targetSpeed)
{
  if (_currentDirection == DIRECTION_FORWARD)
  {
    #ifdef DEBUG
      Serial.println("breaking down forward direction");
    #endif
    rampDownForward(targetSpeed);
  } else
  {
    #ifdef DEBUG
      Serial.println("breaking down backward direction");
    #endif
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
    #ifdef DEBUG
      Serial.println("increasing speed forward by:");
      Serial.println(i);
    #endif
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
    #ifdef DEBUG
      Serial.println("decreasing speed forward by:");
      Serial.println(i);
    #endif
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
    #ifdef DEBUG
      Serial.println("increasing speed backward by:");
      Serial.println(i);
    #endif
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
    #ifdef DEBUG
      Serial.println("decreasing speed backward by:");
      Serial.println(i);
    #endif
    analogWrite(_motorIN1Pin, i);
    _currentSpeed = i;
    delay(ACCELERATION_DELAY_MS);
  }
}
