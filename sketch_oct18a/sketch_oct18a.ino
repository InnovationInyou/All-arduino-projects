char data = 0;
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 
#define SERVOMAX  600 
uint8_t servonum1 = 0;
void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  
}
void loop() {
  if (Serial.available() >0)
  {
    data = Serial.read();      
    Serial.print(data);
    Serial.print("\n");
    
    if (data=='L')
    {
      Serial.println("servo1 is ON");
    int i=0;
    int servo1=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum1, 0, servo1 );
    }
    else if (data=='S')
    {
      Serial.println("servo1 is OFF");
    int i=180;
    int servo1=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum1, 0, servo1 );
    }
    else if (data=='K')
    {
      Serial.println("servo1 is ON");
    int i=90;
    int servo1=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum1, 0, servo1 );
    }

