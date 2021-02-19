 
void setup() {
  Serial.begin(9600);
  pinMode(6,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);

}

void loop() {
  int pushbutton1= digitalRead(6);
  if(pushbutton1==HIGH)
  {
    Serial.write('F');
    Serial.println("\n");
  }

  int pushbutton2= digitalRead(9);
  if(pushbutton2==HIGH)
  {
    Serial.write('B');
    Serial.println("\n");
  }

  int pushbutton3= digitalRead(10);
  if(pushbutton3==HIGH)
  {
    Serial.write('L');
    Serial.println("\n");
  }

  int pushbutton4= digitalRead(11);
  if(pushbutton4==HIGH)
  {
    Serial.write('R');
    Serial.println("\n");
  }
else
{
  Serial.write(' ');
  
}
 unsigned int servo1= analogRead(A0);
  if(servo1>10 && servo1<204)
  {
  Serial.write('A');
  Serial.println("\n");
}
if(servo1>204 && servo1<408)
  {
  Serial.write('C');
  Serial.println("\n");
}
if(servo1>408 && servo1<612)
  {
  Serial.write('D');
  Serial.println("\n");
}
if(servo1>612 && servo1<816)
  {
  Serial.write('E');
  Serial.println("\n");
}
if(servo1>816 && servo1<1013)
  {
  Serial.write('G');
  Serial.println("\n");
}
unsigned int servo2= analogRead(A1);
  if(servo2>10 && servo2<314)
  {
  Serial.write('H');
  Serial.println("\n");
}
if(servo2>314 && servo2<628)
  {
  Serial.write('I');
  Serial.println("\n");
}
if(servo2>628 && servo2<1013)
  {
  Serial.write('J');
  Serial.println("\n");
}

unsigned int servo3= analogRead(A2);
  if(servo3>10 && servo3<314)
  {
  Serial.write('K');
  Serial.println("\n");
}
if(servo3>314 && servo3<628)
  {
  Serial.write('M');
  Serial.println("\n");
}
if(servo3>628 && servo3<1013)
  {
  Serial.write('N');
  Serial.println("\n");
}
unsigned int servo4= analogRead(A3);
  if(servo4>10 && servo4<314)
  {
  Serial.write('O');
  Serial.println("\n");
}
if(servo4>314 && servo4<628)
  {
  Serial.write('P');
  Serial.println("\n");
}
if(servo4>628 && servo4<1013)
  {
  Serial.write('Q');
  Serial.println("\n");
}
unsigned int servo5= analogRead(A4);
  if(servo5>10 && servo5<255)
  {
  Serial.write('S');
  Serial.println("\n");
}
if(servo5>255 && servo5<510)
  {
  Serial.write('T');
  Serial.println("\n");
}
if(servo5>510 && servo5<765)
  {
  Serial.write('U');
  Serial.println("\n");
}
if(servo5>765 && servo5<1013)
  {
  Serial.write('V');
  Serial.println("\n");
}

unsigned int servo6= analogRead(A5);
  if(servo6>10 && servo6<511)
  {
  Serial.write('W');
  Serial.println("\n");
}
if(servo6>511 && servo6<1013)
  {
  Serial.write('X');
  Serial.println("\n");
}
}
