/*
* Open serial monitor, press one of the keys below and click 'Send':
* 'S' - to start all timers
* 'P' - to pause all timers
* 'R' - to restart all timers
* 'T' - to stop all timers
*/
#include "Countimer.h"

Countimer tUp;
Countimer tDown;
Countimer tNone;

void setup()
{
  Serial.begin(9600);
   pinMode(7,INPUT);
   pinMode(8,INPUT);
    // Count-down timer with 21s
  tDown.setCounter(0, 0, 10, tDown.COUNT_DOWN, tDownComplete);
    // Call print_time2() method every 1s.
  tDown.setInterval(print_time2, 1000);
  
  Serial.println("Press one of the keys below and click 'Send':");
  Serial.println("'S' - to start all timers");
  Serial.println("'P' - to pause all timers");
  Serial.println("'R' - to restart all timers");
  Serial.println("'T' - to stop all timers");
}

void loop()
{
 
  int Val1 = digitalRead(7);
  int Val2 = digitalRead(8);

  if (Val1 == 1 ){
    tDown.restart();
    digitalWrite(13,LOW);
  }
  if (Val2 == 1){
    tDown.pause();
    digitalWrite(13,LOW);
  }
  
}

void print_time2()
{
  Serial.print("tDown: ");
  Serial.println(tDown.getCurrentTime());
}
void tDownComplete(){
    digitalWrite(13,HIGH);
    delay(5000);
    digitalWrite(13,LOW);
    tDown.restart();
   }
