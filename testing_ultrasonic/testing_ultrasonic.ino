#include <Servo.h>
long duration;
int distance;
int distance_f;
int distance_r;
int distance_l;
int minimumdistance=50;
int ping();

 Servo servo1;

void setup() {
  pinMode(A1,INPUT);
  pinMode(A0,OUTPUT);
  pinMode(9,OUTPUT);
  servo1.attach(9);
  servo1.write(100);
  
  
  Serial.begin(9600);
  
}

void loop() {
  distance_f=ping();
   if(distance_f > minimumdistance){
    
     delay(400);
   }else{
    
      get_Distance();
      if(distance_r > minimumdistance){
        
        delay(400);
       
      }else if(distance_l > minimumdistance){
         
 
        delay(400);
       
      }
    
   }
}
   void get_Distance(){
  servo1.write(15);
  delay(500);
  int temp_r1=ping();
  servo1.write(45);
  delay(500);
  int temp_r2=ping();
  if(temp_r1<temp_r2){
    distance_r=temp_r1;
  }else{
    distance_r=temp_r2;
    Serial.print("distance at right:  ");
    Serial.println(distance_r);
  }
  servo1.write(100);
  delay(500);
  distance_f=ping();
   Serial.print("distance at front:  ");
    Serial.println(distance_f);
  
  servo1.write(135);
  delay(500);
  int temp_l1=ping();
 servo1.write(180);
  delay(500);
  int temp_l2=ping();
  if(temp_l1<temp_l2){
    distance_l=temp_l1;
  }else{
    distance_l=temp_l2;
     Serial.print("distance at left:  ");
    Serial.println(distance_l);
  }
 servo1.write(100);
  
}
  int ping(){
 digitalWrite(A0, HIGH);
  delayMicroseconds(10);
  digitalWrite(A0, LOW);
  
  duration= pulseIn(A1,HIGH);
  distance=duration*0.034/2;

    Serial.print("object distance=");
    Serial.print("CM");
    Serial.println(distance);
    delay(1000);

}



