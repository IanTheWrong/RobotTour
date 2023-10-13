#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_ConquerorCarxxx0;
MPU6050_getdata AppMPU6050getdata;
int time1 = 0;
int time2 = 0;
ConquerorCarMotionControl status = Forward;

void setup() {
  Serial.begin(9600);
  AppMotor.DeviceDriverSet_Motor_Init();
  AppMPU6050getdata.MPU6050_dveInit();
  delay(2000);
  AppMPU6050getdata.MPU6050_calibration();


}

void loop() {
  static float Yaw;
  AppMPU6050getdata.MPU6050_dveGetEulerAngles(&Yaw);
  Serial.println(Yaw);
  if(Yaw > -90){
    ApplicationFunctionSet_ConquerorCarMotionControl(Left /*direction*/, 60 /*speed*/);
  }
  else if(Yaw < -92){
    ApplicationFunctionSet_ConquerorCarMotionControl(Right /*direction*/, 60 /*speed*/);
  }
  else{
    ApplicationFunctionSet_ConquerorCarMotionControl(stop_it /*direction*/, 255 /*speed*/);
  }

}