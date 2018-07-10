/*
  DRV8871.h - Library for interacting with DRV8871
  Created by Dirk Köhler
*/

#ifndef DRV8871_MotorConfig_h
#define DRV8871_MotorConfig_h

class DRV8871_MotorConfig
{
  public:
    DRV8871_MotorConfig (byte motorIN1Pin, byte motorIN2Pin);
    byte getMotorIN1Pin();
    byte getMotorIN2Pin();
  private:
    byte _motorIN1Pin;
    byte _motorIN2Pin;
};
#endif
