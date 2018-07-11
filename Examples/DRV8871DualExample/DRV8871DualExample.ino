#include <Arduino.h>
#include <DRV8871Dual.h>
#include <DRV8871.h>

//pin configuration
#define MOTOR1_IN1   9
#define MOTOR1_IN2   10
#define MOTOR2_IN1   11
#define MOTOR2_IN2   12

DRV8871 motor1 (MOTOR1_IN1, MOTOR1_IN2);
DRV8871 motor2 (MOTOR2_IN1, MOTOR2_IN2);

DRV8871Dual dualMotorController (&motor1, &motor2);

void setup()
{                          

}

void loop()
{
  dualMotorController.drive(50, dualMotorController.DIRECTION_FORWARD);
  delay (1000);
  dualMotorController.turn(10, dualMotorController.TURN_LEFT);
  delay (1000);
  dualMotorController.drive(50, dualMotorController.DIRECTION_BACKWARD);
  delay (1000);
  dualMotorController.turn(10, dualMotorController.TURN_RIGHT);
  delay (1000);
  dualMotorController.drive(50, dualMotorController.DIRECTION_FORWARD);
  delay (1000);
  dualMotorController.breakdown();
  delay (1000);
}