#include "Countimer.h"

Countimer timer;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
    // Set up count down timer with 10s and call method onComplete() when timer is complete.
    // 00h:00m:10s
  timer.setCounter(1, 0, 0, timer.COUNT_DOWN, onComplete);

    // Print current time every 1s on serial port by calling method refreshClock().
    timer.setInterval(refreshClock, 1000);
}

void refreshClock() {
  Serial.print("Current count time is: ");
    Serial.println(timer.getCurrentTime());
}

void onComplete() {
  Serial.println("Complete!!!");
  Buzzer();
  Pump();
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
        timer.restart();
        break;
        case 'S':
        timer.start();
        break;
      case 'P':
        timer.pause();
        break;
      default:
        break;
    }
  }
}
