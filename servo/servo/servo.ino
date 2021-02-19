char data =0;
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 
#define SERVOMAX  600 
uint8_t servonum = 0;

void setup() 
{
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  
  delay(10);
}
void loop() 
{
 if (Serial.available() >0)
  {
    data = Serial.read();      
    Serial.print(data);
    Serial.print("\n");
    
    if (data=='L')
    {
      Serial.println("servo1 is ON");
      int i=0;
       for (i=0;i<180;i+=2)
    {
       int pulselen= map(i,0,180,SERVOMIN,SERVOMAX);
       pwm.setPWM(servonum, 0, pulselen);
       delay(50);
    }
  }
   else if (data=='K')
     {
      Serial.println("servo1 is ON");
      int j=180;
      for (j=180;j>0;j-=2)
     {
        int pulselen= map(j,0,180,SERVOMIN,SERVOMAX); 
        pwm.setPWM(servonum, 0, pulselen);
        delay(50);
     }
   }
  }
}
