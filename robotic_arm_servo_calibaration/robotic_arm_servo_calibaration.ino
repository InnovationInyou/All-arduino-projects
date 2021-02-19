#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  125 
#define SERVOMAX  575 
uint8_t servonum = 0;
/*
 * servo M1 = 0-180 (    )
 * servo M2 = 0-180 (    )
 * servo M3 = 0-180 (    )
 * servo M4 = 0-180 (    )
 * servo M5 = 0-180 (    )
 * servo M6 = 0-180 (    ) 
 */

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  
}
void loop() {


  int servo1 =2100;
    servo1=map(servo1,2000, 2180, SERVOMIN,SERVOMAX);
    pwm.setPWM(0, 0, servo1 );
}




    
