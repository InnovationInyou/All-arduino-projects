
#include <Servo.h>
Servo myservo;
void setup() {
 myservo.attach(9); // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
   myservo.write(0);
   delay(1000);
   myservo.write(10);
   delay(1000);
   myservo.write(20);
   delay(1000);
   myservo.write(30);
   delay(1000);
   myservo.write(40);
   delay(1000);
   myservo.write(50);
   delay(1000);
   myservo.write(60);
   delay(1000);
   myservo.write(70);
   delay(1000);
   myservo.write(80);
   delay(1000);
   myservo.write(90);
   delay(1000);
   myservo.write(100);
   delay(1000);
   myservo.write(110);
   delay(1000);
   myservo.write(120);
   delay(1000);
   
  
  

}
