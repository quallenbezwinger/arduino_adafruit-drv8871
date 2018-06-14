#include <Arduino.h>
#include <DRV8871.h>

//global debug flag
#define DEBUG

//pin configuration
#define MOTOR_IN1   9
#define MOTOR_IN2   10

DRV8871 motor (
  MOTOR_IN1,
  MOTOR_IN2
);        

void setup() {                          
  #ifdef DEBUG
    Serial.begin(9600);  
    Serial.println("Setup finished");
  #endif
}

void loop() {
  #ifdef DEBUG
  Serial.println("Start loop");
  motor.accForward(20);
  #endif
  delay(1000);
}