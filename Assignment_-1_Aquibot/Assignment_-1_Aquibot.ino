#include "Countimer.h"

Countimer timer;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT); // can connect relay or irf540 
  pinMode(8,OUTPUT);
    // Set up count down timer with __hr__min__s and call method onComplete() when timer is complete.
    //             00h:00m:00s
  timer.setCounter(1  , 0,  0, timer.COUNT_DOWN, onComplete);

    // Print current time every 1s on serial port by calling method refreshClock().
    timer.setInterval(refreshClock, 1000);
}

void refreshClock() {
  Serial.print("Current count time is: ");
    Serial.println(timer.getCurrentTime());
}

void onComplete() {
  Serial.println("Complete!!!");
  Buzzer(); // once timer is complete it will buzz for three second and the stop
  Pump(); // once timer is complete the pump will start for 5 min and then reset the timer automatically
}

void Buzzer(){
  digitalWrite(8,HIGH);
  delay(3000);
  digitalWrite(8,LOW);
}

void Pump(){
  digitalWrite(13,HIGH);
  delay(300000);
  digitalWrite(13,LOW);
  timer.restart();
}
void loop() {
  // Run timer
  timer.run();

    if (Serial.available() > 0)
  {
    char c = toupper(Serial.read());

    switch (c)
    {
      case 'R':
        timer.restart();  // send 'r' in serial moniter to restart the timer 
        break;
        case 'S':  // send 's' in serial moniter to start the timer 
        timer.start();
        break;
      case 'P':   // send 'p' in serial moniter to pause the timer 
        timer.pause();
        break;
      default:
        break;
    }
  }
}
