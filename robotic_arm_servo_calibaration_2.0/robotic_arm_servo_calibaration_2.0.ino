#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  125 
#define SERVOMAX  575 
uint8_t servonum1 = 0;
uint8_t servonum2 = 1;
uint8_t servonum3 = 2;
uint8_t servonum4 = 3;
uint8_t servonum5 = 4;
uint8_t servonum6 = 5;
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
  if(Serial.available()>=2)
 {
 unsigned int servopos=Serial.read();
 unsigned int servopos1=Serial.read();
 unsigned int realservo=(servopos1*256)+servopos;
 Serial.println(realservo);
   
   if( realservo>=1000 && realservo<1180)
  {
    int servo1 =realservo;
    servo1=map(servo1,1000, 1180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum1, 0, servo1 );
    Serial.println("servo1 is ON");
  }

  if( realservo>=2000 && realservo<2180)
  {
    int servo2 =realservo;
    servo2=map(servo2,2000, 2180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum2, 0, servo2 );
    Serial.println("servo2 is ON");
  }


  if( realservo>=3000 && realservo<3180)
  {
    int servo3 =realservo;
    servo3=map(servo3,3000, 3180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum3, 0, servo3 );
    Serial.println("servo3 is ON");
  }
  
  if( realservo>=4000 && realservo<4180)
  {
    int servo4 =realservo;
    servo4=map(servo4,4000, 4180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum4, 0, servo4 );
    Serial.println("servo4 is ON");
  }

  if( realservo>=5000 && realservo<5180)
  {
    int servo5 =realservo;
    servo5=map(servo5,5000, 5180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum5, 0, servo5 );
    Serial.println("servo5 is ON");
  }
  
  if( realservo>=6000 && realservo<6180)
  {
    int servo6 =realservo;
    servo6=map(servo6,6000, 6180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum6, 0, servo6 );   
    Serial.println("servo6 is ON");
  }
}
}

