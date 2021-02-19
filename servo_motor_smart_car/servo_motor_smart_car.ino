#include <Servo.h>  // Includes servo library.
// defines pins numbers
const int trigPin = 9;
const int echoPin = 8;
const int lm1=7;
const int lm2=6;
const int rm1=5;
const int rm2=4;
const int servoPin=10;

Servo myservo;

// defines variables
long duration;
int distance;
int distance_f;
int distance_r;
int distance_l;
int minimumdistance=70;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);

myservo.attach(servoPin);
myservo.write(100);

Serial.begin(9600); // Starts the serial communication
}
void loop() {
   distance_f=ping();
   if(distance_f > minimumdistance){
     front();
     delay(400);
   }else{
      Break();
      get_Distance();
      if(distance_r > minimumdistance){
        right();
        delay(400);
        front();
      }else if(distance_l > minimumdistance){
        left();
        delay(400);
        front();
      }
    
   }
}
void displaydistance(){
     Serial.print("Right Distance : ");
     Serial.print(distance_r);
     Serial.println("");
     Serial.print("Front Distance : ");
     Serial.print(distance_f);
     Serial.println("");
     Serial.print("Left Distance : ");
     Serial.print(distance_l);
     Serial.println("");
  
}
void front(){
Serial.println("Forward Move");
digitalWrite(lm2,HIGH);
digitalWrite(rm2,HIGH);
digitalWrite(lm1,LOW);
digitalWrite(rm1,LOW);

}

void left(){
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
}
void right(){
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void Break(){
  digitalWrite(lm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

void get_Distance(){
  myservo.write(15);
  delay(500);
  int temp_r1=ping();
  myservo.write(45);
  delay(500);
  int temp_r2=ping();
  if(temp_r1<temp_r2){
    distance_r=temp_r1;
  }else{
    distance_r=temp_r2;
  }
  myservo.write(100);
  delay(500);
  distance_f=ping();
  
  myservo.write(135);
  delay(500);
  int temp_l1=ping();
  myservo.write(180);
  delay(500);
  int temp_l2=ping();
  if(temp_l1<temp_l2){
    distance_l=temp_l1;
  }else{
    distance_l=temp_l2;
  }
  myservo.write(100);
  
}

int ping(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  return distance;
}           
