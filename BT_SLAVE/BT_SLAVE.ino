char data=0;
#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

void setup() {
 Serial.begin(9600);
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(36,OUTPUT);
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);
  myservo6.attach(7);
  myservo1.write(120);
  myservo2.write(150);
  myservo3.write(180);
  myservo4.write(150);
  myservo5.write(90);
}

void loop() {
   
 if(Serial.available()>0)
 {
  data=Serial.read();
  Serial.println(data);
  if(data == 'F') 
      {  
              
        digitalWrite(26, HIGH);
        digitalWrite(28, LOW);
        digitalWrite(34, LOW);
        digitalWrite(36, HIGH);
      }   
       if(data == 'B') 
      {        
         digitalWrite(26, LOW);
        digitalWrite(28, HIGH);
        digitalWrite(34, HIGH);
        digitalWrite(36, LOW);   
         
  }
  if(data == 'L') 
      {        
         digitalWrite(26, LOW);
         digitalWrite(28, HIGH);
         digitalWrite(34, LOW);
         digitalWrite(36, HIGH);    
         
  }
  if(data == 'R') 
      {        
         digitalWrite(26, HIGH);
         digitalWrite(28, LOW);
         digitalWrite(34, HIGH);
         digitalWrite(36, LOW);
        }
  if(data== ' ')
      {        
         digitalWrite(26, LOW);
         digitalWrite(28, LOW);
         digitalWrite(34, LOW);
         digitalWrite(36, LOW);
         }
      
    if (data == 'A')
{
    myservo1.write(0);
}
if (data == 'C')
{
    myservo1.write(20);
}
if (data == 'D')
{
    myservo1.write(40);
}
if (data == 'E')
{
    myservo1.write(60);
}
 if (data == 'G')
{
    myservo1.write(80); 
}
 if (data == 'H')
{
    myservo1.write(100); 
}
if (data == 'I')
{
    myservo1.write(120);
}
if (data == 'J')
{
    myservo1.write(140);
}
  if (data == 'K')
{
     myservo1.write(160);
}
 if (data == 'M')
{
     myservo1.write(180);
}
if (data == 'N')
{
     myservo1.write(120);
}
    









if (data == 'O')
  {
     myservo2.write(150);
  }
if (data == 'P')
  {
     myservo2.write(130);
  }
if (data == 'Q')
  {
     myservo2.write(110);
  }
if (data == 'S')
  {
       myservo2.write(90);
  }
if (data == 'T')
  {
     myservo2.write(70);
  }
if (data == 'U')
  {
      myservo2.write(50);
  }
if (data == 'V')
  {
       myservo2.write(30);
  }
if (data == 'W')
  {
       myservo2.write(10);
  }
if (data == 'X')
  {
      myservo2.write(70);
  }
if (data == 'Y')
  {
     
     myservo2.write(150);
  }

  









if (data == 'Z')
{
     myservo3.write(100);
}
if (data == 'a')
{
     myservo3.write(110); 
}
if (data == 'b')
{
   myservo3.write(120);  
}
if (data == 'c')
{
     myservo3.write(130); 
}
if (data == 'd')
{
      myservo3.write(140);
}
if (data == 'e')
{
       myservo3.write(150);
}
if (data == 'f')
{
     myservo3.write(160);
 
}
 if (data == 'g')
{
   myservo3.write(170);
}
if (data == 'h')
{
   myservo3.write(180);
}










if(data =='i')
{
  myservo4.write(100);
}

if(data =='j')
{
   myservo4.write(110);
}
if(data =='k')
{
    myservo4.write(120);
}
if(data =='l')
{
   myservo4.write(130);
}
if(data =='m')
{
     myservo4.write(140);
}
if(data =='n')
{
     myservo4.write(150);
}

   









if (data == 'o')
{
    myservo5.write(0);
} 
if (data == 'p')
{
   myservo5.write(20);
} 
if (data == 'q')
{
      myservo5.write(40);
} 
if (data == 'r')
{
      myservo5.write(60);
}
 if (data == 's')
{
       myservo5.write(80);
} 
if (data == 't')
{
       myservo5.write(100);
} 
if (data == 'u')
{
      myservo5.write(120);
} 
if (data == 'v')
{
       myservo5.write(140);
} 
if (data == 'w')
{
      myservo5.write(160);
} 
if (data == 'x')
{
      myservo5.write(180);
} 
if (data == 'y')
{
     myservo5.write(90);
} 

   










if (data == 'z')
{
   myservo6.write(100);  
}
if (data == '0')
{
    myservo6.write(180);
}

 }
}
