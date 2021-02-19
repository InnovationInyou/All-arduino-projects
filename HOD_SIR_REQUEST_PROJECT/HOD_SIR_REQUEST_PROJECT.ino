// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <Servo.h>
Servo myservo;


void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
myservo.attach(6);
pinMode(5,INPUT);

}

void loop() {
  int val=digitalRead(5);
   myservo.write( 90 );
  if (val == LOW){
   myservo.write( 180 );
   delay(1400);
    
     
 
  }
  
}
