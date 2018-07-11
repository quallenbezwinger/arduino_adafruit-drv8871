/*
  DRV8871Dual.h - Library for interacting with DRV8871Dual
  Created by Dirk Köhler
*/

#ifndef DRV8871Dual_h
#define DRV8871Dual_h

#include "Arduino.h"
#include "DRV8871.h"

class DRV8871Dual
{
  public:
    DRV8871Dual (DRV8871* motor1, DRV8871* motor2);
    const byte DIRECTION_FORWARD = 1;  
    const byte DIRECTION_BACKWARD = 2;
    const byte TURN_LEFT = 2;  
    const byte TURN_RIGHT = 3;  
    void drive (byte speed, byte direction);
    void turn (byte speed, byte direction);
    void breakdown (byte targetSpeed = 0);
  private:
    DRV8871* _motor1;
    DRV8871* _motor2;
};
#endif
