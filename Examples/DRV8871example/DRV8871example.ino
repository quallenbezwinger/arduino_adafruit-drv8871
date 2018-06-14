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
  Serial.println("ramp up forward from zero to 50");
  motor.accelerate(50,motor.DIRECTION_FORWARD);
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  delay(2000);

  Serial.println("increasing forward speed by ramp up from 50 to 100");
  motor.accelerate(100,motor.DIRECTION_FORWARD);
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  delay(2000);

  Serial.println("switching from forward 100 to backward 70");
  motor.accelerate(70,motor.DIRECTION_BACKWARD);
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  delay(2000);

  Serial.println("breaking from backward 70 to backward 10");
  motor.breakdown(10);
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  delay(2000);

  Serial.println("breaking from backward 10 to backward 0");
  motor.breakdown();
  Serial.println("Current speed:");
  Serial.println(motor.currentSpeed());
  delay(2000);
 
}