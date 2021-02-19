#include "NewPing.h"
#define HCSR04_PIN_TRIG  3
#define HCSR04_PIN_ECHO 2
NewPing hcsr04(HCSR04_PIN_TRIG,HCSR04_PIN_ECHO);
void setup() {
  Serial.begin(9600);
  pinMode (4,OUTPUT);
}

void loop() {
  int hcsr04Dist = hcsr04.ping_cm();
    delay(10);
    Serial.print(F("Distance: ")); Serial.print(hcsr04Dist); Serial.println(F("[cm]"));
    if (hcsr04Dist <=200){
     digitalWrite(4, HIGH);
    }
    if (hcsr04Dist >200){
     digitalWrite(4, LOW);
    }
}
