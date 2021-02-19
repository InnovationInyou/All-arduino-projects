#include <Servo.h>
Servo myservo;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  myservo.attach(7); 
}

void loop() {
  int IR;
  IR=analogRead(A0);
  Serial.println(IR);
  delay(1000);
if (IR<600)
{
 myservo.write(1000);
 delay(1000);
 }
}

