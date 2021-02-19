char data =0;
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 
#define SERVOMAX  600 
uint8_t servonum1 = 0;
uint8_t servonum2 = 1;
uint8_t servonum3 = 2;
uint8_t servonum4 = 3;
uint8_t servonum5 = 4;
uint8_t servonum6 = 5;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  
}
void loop() {
 int a=180;
int servo=map(a,0, 180, SERVOMIN,SERVOMAX);
  pwm.setPWM(servonum1, 0, servo );
  pwm.setPWM(servonum2, 0, servo );
  pwm.setPWM(servonum3, 0, servo );
  pwm.setPWM(servonum4, 0, servo );
  pwm.setPWM(servonum5, 0, servo );
  pwm.setPWM(servonum6, 0, servo );
  Serial.println("all servos are OFF");
  if (Serial.available() >0)
  {
    char data = Serial.read();      
    Serial.print(data);          
  }
   if( data=="S")
  {
    int i=180;
  int servo=map(i,0, 180, SERVOMIN,SERVOMAX);
  pwm.setPWM(servonum1, 0, servo );
  pwm.setPWM(servonum2, 0, servo );
  pwm.setPWM(servonum3, 0, servo );
  pwm.setPWM(servonum4, 0, servo );
  pwm.setPWM(servonum5, 0, servo );
  pwm.setPWM(servonum6, 0, servo );
    Serial.println("servo is OFF");
  }
   if( data=="L")
  {
    int i=0;
    int servo1=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum1, 0, servo1 );
    Serial.println("servo1 is ON");
  }
  
  if( data=="k")
  {
    int i=90;
  int  servo1=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum1, 0, servo1 );
    Serial.println("servo1 is ON");
  }


  if( data=="J")
  {
    int i=0;
    int servo2=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum2, 0, servo2 );
    Serial.println("servo2 is ON");
  }
  
  if( data=="I")
  {
    int i=90;
    int servo2=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum2, 0, servo2 );
    Serial.println("servo2 is ON");
  }


  if( data=="H")
  {
    int i=0;
    int servo3=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum3, 0, servo3 );
    Serial.println("servo3 is ON");
  }
  
  if( data=="G")
  {
    int i=90;
    int servo3=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum3, 0, servo3 );
    Serial.println("servo3 is ON");
  }



  if( data=="F")
  {
    int i=0;
    int servo4=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum4, 0, servo4 );
    Serial.println("servo4 is ON");
  }
  
  if( data=="E")
  {
    int i=90;
    int servo4=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum4, 0, servo4 );
    Serial.println("servo4 is ON");

  }
    if( data=="D")
  {
    int i=0;
    int servo5=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum5, 0, servo5 );
    Serial.println("servo5 is ON");
  }
  
  if( data=="C")
  {
    int i=90;
    int servo5=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum5, 0, servo5 );
    Serial.println("servo5 is ON");
  }



  if( data=="B")
  {
    int i=0;
    int servo6=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum6, 0, servo6 );
    Serial.println("servo6 is ON");
  }
  
  if( data=="A")
  {
    int i=90;
    int servo6=map(i,0, 180, SERVOMIN,SERVOMAX);
    pwm.setPWM(servonum6, 0, servo6 );
    Serial.println("servo6 is ON");
  }
}

  
