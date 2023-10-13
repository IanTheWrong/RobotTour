#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0.h"
#include "ApplicationFunctionSet_xxx0.cpp"

DeviceDriverSet_Motor AppMotor;
Application_xxx Application_ConquerorCarxxx0;
MPU6050_getdata AppMPU6050getdata;
int time1 = 0;
int time2 = 0;
ConquerorCarMotionControl status = Forward;
static void turnLeft(float Yaw, int Speed){
  if(Yaw > -90){
    ApplicationFunctionSet_ConquerorCarMotionControl(Left /*direction*/, Speed /*speed*/);
  }
  else if(Yaw < -92){
    ApplicationFunctionSet_ConquerorCarMotionControl(Right /*direction*/, Speed /*speed*/);
  }
  else{
    ApplicationFunctionSet_ConquerorCarMotionControl(stop_it /*direction*/, Speed /*speed*/);
  }
}
void setup() {
  Serial.begin(9600);
  AppMotor.DeviceDriverSet_Motor_Init();
  AppMPU6050getdata.MPU6050_dveInit();
  delay(2000);
  AppMPU6050getdata.MPU6050_calibration();


}

void loop() {
  static float YawC;
  AppMPU6050getdata.MPU6050_dveGetEulerAngles(&YawC);
  Serial.println(YawC);
  turnLeft(YawC, 60);

}