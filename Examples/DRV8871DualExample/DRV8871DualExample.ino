#include <Arduino.h>
#include <DRV8871.h>
#include <DRV8871_MotorConfig.h>

//pin configuration
#define MOTOR1_IN1   9
#define MOTOR1_IN2   10
#define MOTOR2_IN1   11
#define MOTOR2_IN2   12

DRV8871_MotorConfig motor1 (MOTOR1_IN1, MOTOR1_IN2);
DRV8871_MotorConfig motor2 (MOTOR2_IN1, MOTOR2_IN2);
DRV8871_MotorConfig *pMotorCollection[2] = {&motor1,&motor2};

DRV8871 dualMotorController (pMotorCollection);

void setup()
{                          

}

void loop()
{
  /*dualMotorController.drive(50, dualMotorController.DIRECTION_FORWARD, 10);
  delay (1000);
  dualMotorController.turn(10, dualMotorController.TURN_LEFT, 10);
  delay (1000);
  dualMotorController.drive(50, dualMotorController.DIRECTION_BACKWARD, 10);
  delay (1000);
  dualMotorController.turn(10, dualMotorController.TURN_RIGHT, 10);
  delay (1000);
  dualMotorController.drive(50, dualMotorController.DIRECTION_FORWARD, 10);
  delay (1000);
  dualMotorController.breakdown();
  delay (1000);*/
}