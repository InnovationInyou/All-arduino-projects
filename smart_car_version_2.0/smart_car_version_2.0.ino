#include <NewPing.h>
#include <Servo.h>
#define TRIG_PIN A4
#define ECHO_PIN A5
#define MAX_DISTANCE 200
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;
boolean goesForward=false;
int distance = 100;
int speedSet = 0;
const int motorPin1 = 11;
const int motorPin2 = 10;
//Motor B
const int motorPin3 = 6;
const int motorPin4 = 5;
void setup() {
 myservo.attach(9);
 myservo.write(100);
 delay(2000);
 distance = readPing();
 delay(100);
 distance = readPing();
 delay(100);
 distance = readPing();
 delay(100);
 distance = readPing();
 delay(100);
}
void loop() {
int distanceR = 0;
int distanceL = 0;
delay(40);
if(distance<=40)
{
 moveStop();
 delay(100);
 moveBackward();
 delay(1274);
 moveStop();
 delay(200);
 distanceR = lookRight();
 delay(200);
 distanceL = lookLeft();
 delay(200);
 if(distanceR>=distanceL)
 {
 turnRight();
 delay(1000);
 moveStop();
 }else
 {
 turnLeft();
 delay(1000);
 moveStop();
 }
}else
{
 moveForward();
}
distance = readPing();
}
int lookRight()
{
 myservo.write(15);
 delay(500);
 int distance = readPing();
 delay(100);
 myservo.write(100);
 return distance;
}
int lookLeft()
{
 myservo.write(170);
 delay(500);
 int distance = readPing();
 delay(100);
 myservo.write(100);
 return distance;
 delay(100);
}
int readPing() {
 delay(70);
 int cm = sonar.ping_cm();
 if(cm==0)
 {
 cm = 250;
 }
 return cm;
}
void moveStop() {
 digitalWrite(motorPin1,LOW);
 digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin4,LOW);
 }

void moveForward() {
 digitalWrite(motorPin1, HIGH);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin4, LOW);

}
void moveBackward() {
 
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin4, HIGH);

}
void turnRight() {
digitalWrite(motorPin1, HIGH);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin4, HIGH);
 delay(300);
moveForward();

}
void turnLeft() {
 digitalWrite(motorPin1, LOW);
 digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin4, LOW);
 delay(300);
 moveForward();
}
