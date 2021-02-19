int digit1 = 10; 
int digit2 = 11; 
int digit3 = 12; 
int digit4 = 13; 

//Pin mapping from Arduino to the ATmega DIP28 if you need it
//http://www.arduino.cc/en/Hacking/PinMapping
int segA = 2; //Display pin A
int segB = 3; //Display pin b
int segC = 4; //Display pin c
int segD = 5; //Display pin d
int segE = 6; //Display pin e
int segF = 7; //Display pin f
int segG = 8; //Display pin g
int segDP = 9;// Display pin dot
byte SW0 = A0;
byte SW1 = A1;
byte SW2 = A2;
#include <Time.h>
#include <TimeLib.h>
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

void setup() {
  //  Serial.begin(57600);
  Wire.begin();
  RTC.begin();

Wire.write(0x07); 

 Wire.write(0x10); 
Wire.endTransmission();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
   
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
   pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  Serial.begin(9600);
   pinMode(SW0, INPUT);  // for this use a slide switch
  pinMode(SW1, INPUT);  // N.O. push button switch
  pinMode(SW2, INPUT);  // N.O. push button switch

  digitalWrite(SW0, HIGH); // pull-ups on
  digitalWrite(SW1, HIGH);
  digitalWrite(SW2, HIGH);
 Serial.println("test for niq_ro");
}
void loop() {
digitalWrite(segDP, HIGH);
  DateTime now = RTC.now();
  int timp = now.hour()*100+now.minute();

  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(" -> ");
  Serial.print(timp);
  Serial.println(" !");
 
   
   for(int i = 400 ; i >0  ; i--) {
     if (timp > 1000) displayNumber01(timp); 
     else displayNumber02(timp); 
   } 

   for(int i = 400 ; i >0  ; i--) {
     if (timp > 1000) displayNumber03(timp); 
     else displayNumber04(timp); 
   } 
if (!(digitalRead(SW0)))
  set_time(); // hold the switch to set time
  
}
void set_time()   {
  byte minutes1 = 0;
  byte hours1 = 0;
  byte minutes = minute();
  byte hours = hour();

  while (!digitalRead(SW0))  // set time switch must be released to exit
  {
    minutes1=minutes;
    hours1=hours;
    
     
    while (!digitalRead(SW1)) // set minutes
    { 
     minutes++;  
   
    if (minutes > 59) 
    minutes = 0;
     for(int i = 20 ; i >0  ; i--) 
     {
       int timp= hours*100+minutes; 
     if (timp > 1000) 
     displayNumber01(timp); 
     else displayNumber02(timp);
     }

      
      
      
      
    delay(150);    
    }

    while (!digitalRead(SW2)) // set hours
    { 
     hours++;          
     
     if (hours > 23) 
     hours = 0;
    
     for(int i = 20 ; i >0  ; i--) {
     int timp= hours*100+minutes;
     if (timp > 1000) 
     displayNumber01(timp); 
     else displayNumber02(timp);
     }
        
      
     delay(150);
    }

   
     
     for(int i = 20 ; i >0  ; i--) {
     displayNumber01(hours*100+minutes); 
     }
     setTime(hours,minutes,0,0,0,0);
 //  delay(150);
    
  }
  
}
void displayNumber01(int toDisplay) {
#define DISPLAY_BRIGHTNESS  1000

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch(digit) {
    case 1:
     digitalWrite(digit1, DIGIT_ON);
     digitalWrite(segDP, LOW);
      break;
   case 2:
      digitalWrite(digit2, DIGIT_ON);
      digitalWrite(segDP, LOW);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      digitalWrite(segDP, LOW);
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      digitalWrite(segDP, LOW);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS); 

     //Turn off all segments
    lightNumber(10); 

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
}
} 

void displayNumber02(int toDisplay) {
#define DISPLAY_BRIGHTNESS  1000

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch(digit) {
    case 1:
     lightNumber(10); 
     digitalWrite(segDP, LOW);
     break;
   case 2:
      digitalWrite(digit2, DIGIT_ON);
      digitalWrite(segDP, LOW);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      digitalWrite(segDP, LOW);
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      digitalWrite(segDP, LOW);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS); 

     //Turn off all segments
    lightNumber(10); 

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
}
} 

void displayNumber03(int toDisplay) {
#define DISPLAY_BRIGHTNESS  1000

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch(digit) {
    case 1:
     digitalWrite(digit1, DIGIT_ON);
     digitalWrite(segDP, HIGH);
      break;
   case 2:
      digitalWrite(digit2, DIGIT_ON);
      digitalWrite(segDP, HIGH);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      digitalWrite(segDP, HIGH);
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      digitalWrite(segDP, HIGH);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS); 

     //Turn off all segments
    lightNumber(10); 

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
}
} 

void displayNumber04(int toDisplay) {
#define DISPLAY_BRIGHTNESS  1000

#define DIGIT_ON  HIGH
#define DIGIT_OFF  LOW

  for(int digit = 4 ; digit > 0 ; digit--) {

    //Turn on a digit for a short amount of time
    switch(digit) {
    case 1:
     lightNumber(10); 
     digitalWrite(segDP, HIGH);
     break;
   case 2:
      digitalWrite(digit2, DIGIT_ON);
      digitalWrite(segDP, HIGH);
      break;
    case 3:
      digitalWrite(digit3, DIGIT_ON);
      digitalWrite(segDP, HIGH);
      break;
    case 4:
      digitalWrite(digit4, DIGIT_ON);
      digitalWrite(segDP, HIGH);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS); 

     //Turn off all segments
    lightNumber(10); 

    //Turn off all digits
    digitalWrite(digit1, DIGIT_OFF);
    digitalWrite(digit2, DIGIT_OFF);
    digitalWrite(digit3, DIGIT_OFF);
    digitalWrite(digit4, DIGIT_OFF);
}
} 

void lightNumber(int numberToDisplay) {

#define SEGMENT_ON  LOW
#define SEGMENT_OFF HIGH

  switch (numberToDisplay){

  case 0:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 1:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 2:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_OFF);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 3:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 4:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 5:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 6:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 7:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;

  case 8:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_ON);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  case 9:
    digitalWrite(segA, SEGMENT_ON);
    digitalWrite(segB, SEGMENT_ON);
    digitalWrite(segC, SEGMENT_ON);
    digitalWrite(segD, SEGMENT_ON);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_ON);
    digitalWrite(segG, SEGMENT_ON);
    break;

  // all segment are ON
  case 10:
    digitalWrite(segA, SEGMENT_OFF);
    digitalWrite(segB, SEGMENT_OFF);
    digitalWrite(segC, SEGMENT_OFF);
    digitalWrite(segD, SEGMENT_OFF);
    digitalWrite(segE, SEGMENT_OFF);
    digitalWrite(segF, SEGMENT_OFF);
    digitalWrite(segG, SEGMENT_OFF);
    break;
  
  }
}

