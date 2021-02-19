// Starting of Program

int m1a = 4;
int m1b = 5;
int m2a = 10;
int m2b = 11;
char val;
void setup() 
{  
pinMode(4, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(5, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(10, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(11, OUTPUT);  // Digital pin 13 set as output Pin
Serial.begin(9600);
}
void loop()
{
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }
  if( val == 'F') // Forward
    {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);  
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH); 
    }
  
    else if(val == 'L') //Left
    {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    }
    else if(val == 'R') //Right
    {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW); 
    }
    
  else if(val == 'S') //Stop
    {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11 LOW); 
    }
  else if(val == 'I') //Forward Right

    {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
  else if(val == 'J') //Backward Right
    {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
   else if(val == 'G') //Forward Left
    {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(10, HIGH);     
    digitalWrite(11, LOW);
    }
  else if(val == 'H') //Backward Left
    {
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
}
}
