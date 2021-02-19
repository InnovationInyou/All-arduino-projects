int leftsensor=2;
int rightsensor=3;
int leftMotor=10;
int rightMotor=11;


void setup()
{
  pinMode (leftMotor, OUTPUT);
  pinMode (rightMotor, OUTPUT);
 pinMode(leftsensor,INPUT);
 pinMode(rightsensor,INPUT);
 }
void loop()
{
 

 
 rightMotor=digitalRead(rightsensor);
 leftMotor=digitalRead(leftsensor);
   if( leftsensor==LOW,rightsensor==LOW)
   {
     digitalWrite (leftMotor, LOW);
     digitalWrite (rightMotor, LOW);
   }
   if( leftsensor==HIGH, rightsensor==LOW)
    {
      digitalWrite (leftMotor, HIGH);
      digitalWrite (rightMotor, LOW);
    }
   if (leftsensor==LOW, rightsensor==HIGH)
   {
   digitalWrite (leftMotor, LOW);
   digitalWrite (rightMotor, HIGH);
   }
   
     if (leftsensor==HIGH,rightsensor==HIGH)
     {digitalWrite (rightMotor, HIGH);
       digitalWrite (leftMotor, HIGH);
     }
      
    }
