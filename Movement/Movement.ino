#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_ConquerorCarxxx0;
MPU6050_getdata AppMPU6050getdata;
double time1 = 0;
double targetTime = time1*1000;
ConquerorCarMotionControl status = Forward;


void setup() {
  Serial.begin(9600);
  AppMotor.DeviceDriverSet_Motor_Init();
  AppMPU6050getdata.MPU6050_dveInit();
  delay(2000);
  AppMPU6050getdata.MPU6050_calibration();


}

void loop() {
  static float YawC;
  unsigned long mil;
  digitalWrite(7, HIGH);
  analogWrite(5, 255);
}