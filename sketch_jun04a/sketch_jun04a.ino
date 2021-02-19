#include <Servo.h>
Servo myservo;  
int trigPin = 11;    // Trigger
int echoPin = 10;    // Echo
long duration, cm, inches; 
void setup() {
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(10, INPUT);  //Sets digital pin 13 as output pin
   myservo.attach(9);  
        Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
    pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
    duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  if (cm<10){
     myservo.write(0);  
   
  }
  else
{
    myservo.write(90);                  
  }
}



