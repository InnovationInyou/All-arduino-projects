 
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
 if(servo1>10 && servo1<100)
  {
  Serial.write('A');
  Serial.println("\n");
}
if(servo1>100 && servo1<190)
  {
  Serial.write('C');
  Serial.println("\n");
}
if(servo1>190 && servo1<280)
  {
  Serial.write('D');
  Serial.println("\n");
}
if(servo1>280 && servo1<370)
  {
  Serial.write('E');
  Serial.println("\n");
}
if(servo1>370 && servo1<460)
  {
  Serial.write('G');
  Serial.println("\n");
}
if(servo1>460 && servo1<550)
  {
  Serial.write('H');
  Serial.println("\n");
}
if(servo1>550 && servo1<640)
  {
  Serial.write('I');
  Serial.println("\n");
}
if(servo1>640 && servo1<730)
  {
  Serial.write('J');
  Serial.println("\n");
}
if(servo1>730 && servo1<820)
  {
  Serial.write('K');
  Serial.println("\n");
}
if(servo1>820 && servo1<910)
  {
  Serial.write('M');
  Serial.println("\n");
}
if(servo1>910 && servo1<1000)
  {
  Serial.write('N');
  Serial.println("\n");
}









unsigned int servo2= analogRead(A1);
 
  if(servo2>10 && servo2<100)
  {
  Serial.write('O');
  Serial.println("\n");
}
if(servo2>100 && servo2<200)
  {
  Serial.write('P');
  Serial.println("\n");
}

if(servo2>200 && servo2<300)
  {
  Serial.write('Q');
  Serial.println("\n");
}
if(servo2>300 && servo2<400)
  {
  Serial.write('S');
  Serial.println("\n");
}
if(servo2>400 && servo2<500)
  {
  Serial.write('T');
  Serial.println("\n");
}
if(servo2>500 && servo2<600)
  {
  Serial.write('U');
  Serial.println("\n");
}
if(servo2>600 && servo2<700)
  {
  Serial.write('V');
  Serial.println("\n");
}
if(servo2>700 && servo2<800)
  {
  Serial.write('W');
  Serial.println("\n");
}
if(servo2>800 && servo2<900)
  {
  Serial.write('X');
  Serial.println("\n");
}
if(servo2>900 && servo2<1000)
  {
  Serial.write('Y');
  Serial.println("\n");
}











unsigned int servo3= analogRead(A2);
  if(servo3>10 && servo3<111)
  {
  Serial.write('Z');
  Serial.println("\n");
}
if(servo3>111 && servo3<222)
  {
  Serial.write('a');
  Serial.println("\n");
}
if(servo3>222 && servo3<333)
  {
  Serial.write('b');
  Serial.println("\n");
}
if(servo3>333 && servo3<444)
  {
  Serial.write('c');
  Serial.println("\n");
}
if(servo3>444 && servo3<555)
  {
  Serial.write('d');
  Serial.println("\n");
}
if(servo3>555 && servo3<666)
  {
  Serial.write('e');
  Serial.println("\n");
}
if(servo3>666 && servo3<777)
  {
  Serial.write('f');
  Serial.println("\n");
}
if(servo3>777 && servo3<888)
  {
  Serial.write('g');
  Serial.println("\n");
}
if(servo3>888 && servo3<999)
  {
  Serial.write('h');
  Serial.println("\n");
}












unsigned int servo4= analogRead(A3);

  if(servo4>10 && servo4<166)
  {
  Serial.write('i');
  Serial.println("\n");
}
if(servo4>166 && servo4<332)
  {
  Serial.write('j');
  Serial.println("\n");
}
if(servo4>332 && servo4<498)
  {
  Serial.write('k');
  Serial.println("\n");
}
if(servo4>498 && servo4<664)
  {
  Serial.write('l');
  Serial.println("\n");
}
if(servo4>664 && servo4<830)
  {
  Serial.write('m');
  Serial.println("\n");
}
if(servo4>830 && servo4<1000)
  {
  Serial.write('n');
  Serial.println("\n");
}










unsigned int servo5= analogRead(A4);

  if(servo5>10 && servo5<100)
  {
  Serial.write('o');
  Serial.println("\n");
}
if(servo5>100 && servo5<190)
  {
  Serial.write('p');
  Serial.println("\n");
}
if(servo5>190 && servo5<280)
  {
  Serial.write('q');
  Serial.println("\n");
}
if(servo5>280 && servo5<370)
  {
  Serial.write('r');
  Serial.println("\n");
}
if(servo5>370 && servo5<460)
  {
  Serial.write('s');
  Serial.println("\n");
}
if(servo5>460 && servo5<550)
  {
  Serial.write('t');
  Serial.println("\n");
}
if(servo5>550 && servo5<640)
  {
  Serial.write('u');
  Serial.println("\n");
}
if(servo5>640 && servo5<730)
  {
  Serial.write('v');
  Serial.println("\n");
}
if(servo5>730 && servo5<820)
  {
  Serial.write('w');
  Serial.println("\n");
}
if(servo5>820 && servo5<910)
  {
  Serial.write('x');
  Serial.println("\n");
}
if(servo5>910 && servo5<1000)
  {
  Serial.write('y');
  Serial.println("\n");
}













unsigned int servo6= analogRead(A5);
  if(servo6>10 && servo6<500)
  {
  Serial.write('z');
  Serial.println("\n");
}
if(servo6>500 && servo6<1000)
  {
  Serial.write('0');
  Serial.println("\n");
}

}
