/*
  DRV8871.h - Library for interacting with DRV8871
  Created by Dirk.
*/

#ifndef DRV8871_h
#define DRV8871_h

#include "Arduino.h"

class DRV8871
{
  public:
    DRV8871 (byte motorIN1Pin, byte motorIN2Pin);
    void accForward(byte targetSpeed);
  private:
    byte _motorIN1Pin;
    byte _motorIN2Pin;
};
#endif
