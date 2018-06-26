#include <Arduino.h>
#include <DRV8871.h>

//pin configuration
#define MOTOR_IN1   9
#define MOTOR_IN2   10

DRV8871 motor (
  MOTOR_IN1,
  MOTOR_IN2
);        

void setup() {                          
  Serial.begin(9600);  
  Serial.println("Setup finished");
}

void loop() {
  Serial.println("ramp up forward from zero to 100");
  motor.drive(100, motor.DIRECTION_FORWARD, 10);
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  Serial.println("Current direction:");
  Serial.println(motor.currentDirection());
  delay(2000);

  Serial.println("increasing forward speed by ramp up from 100 to 255");
  motor.drive(255, motor.DIRECTION_FORWARD, 8);
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  Serial.println("Current direction:");
  Serial.println(motor.currentDirection());
  delay(2000);

  Serial.println("switching from forward 255 to backward 150");
  motor.drive(150, motor.DIRECTION_BACKWARD, 5);
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  Serial.println("Current direction:");
  Serial.println(motor.currentDirection());
  delay(4000);

  Serial.println("breaking from backward 150 to backward 80");
  motor.breakdown(4);
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  Serial.println("Current direction:");
  Serial.println(motor.currentDirection());
  delay(4000);

  Serial.println("breaking from backward 80 to backward 0 instantly");
  motor.breakdown();
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  Serial.println("Current direction:");
  Serial.println(motor.currentDirection());
  delay(4000);
}