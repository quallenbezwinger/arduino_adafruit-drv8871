/*
  DRV8871.h - Library for interacting with DRV8871
  Created by Dirk Köhler
*/

#ifndef DRV8871_h
#define DRV8871_h

#include "Arduino.h"

class DRV8871
{
  public:
    DRV8871 (byte motorIN1Pin, byte motorIN2Pin);
    const byte DIRECTION_FORWARD = 1;
    const byte DIRECTION_BACKWARD = 0;
    void accelerate(byte targetSpeed, byte direction);
    void breakdown(byte targetSpeed = 0);
    byte currentSpeed();
    byte currentDirection();
  private:
    const byte ACCELERATION_DELAY_MS = 10;
    byte _motorIN1Pin;
    byte _motorIN2Pin;
    byte _currentSpeed = 0;
    byte _currentDirection;
    void rampUpForward(byte targetSpeed);
    void rampDownForward(byte targetSpeed);
    void rampUpBackward(byte targetSpeed);
    void rampDownBackward(byte targetSpeed);
};
#endif
