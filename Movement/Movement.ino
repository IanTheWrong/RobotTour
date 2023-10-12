#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"
#include "MPU6050.h"
#include "MPU6050_getdata.h"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_SmartRobotCarxxx0;
double t=(90+6)/136.29*1000.;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  AppMotor.DeviceDriverSet_Motor_Init();
  delay(2000);
  // Moves Backward
  move(Left /*direction*/, 255 /*speed*/);
  delay(t);
  // The Delay below it is how long it moves in that direction
  //If no delay then will go on forever
  move(Forward /*direction*/, 50 /*speed*/);
  delay(1000);
  move(stop_it /*direction*/, 20 /*speed*/);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);    


}