void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);

}

void loop() {
  unsigned int servo1= analogRead(A0);
  if(servo1>10)
  {
 unsigned servoin1=map(servo1,0,1023,1000,2000);
  Serial.print(servoin1);
  Serial.println("\n");
  delay(100);
}

unsigned int servo2= analogRead(A1);
  if(servo2>10)
  {
  unsigned servoin2=map(servo2,0,1023,3000,4000);
  Serial.print(servoin2);
  Serial.println("\n");
  delay(100);
}


unsigned int servo3= analogRead(A2);
  if(servo3>10)
  {
  unsigned servoin3=map(servo3,0,1023,5000,6000);
  Serial.print(servoin3);
  Serial.println("\n");
  delay(100);
}

unsigned int servo4= analogRead(A3);
  if(servo4>10)
  {
  unsigned servoin4=map(servo4,0,1023,7000,8000);
  Serial.print(servoin4);
  Serial.println("\n");
  delay(100);
}

unsigned int servo5= analogRead(A4);
  if(servo5>10)
  {
  unsigned servoin5=map(servo5,0,1023,9000,10000);
  Serial.print(servoin5);
  Serial.println("\n");
  delay(100);
}

unsigned int servo6= analogRead(A5);
  if(servo6>10)
  {
  unsigned servoin6=map(servo6,0,1023,11000,12000);
  Serial.print(servoin6);
  Serial.println("\n");
  delay(100);
}

}