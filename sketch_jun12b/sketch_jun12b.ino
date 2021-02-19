char data = 0;
void setup() 
{
 Serial.begin(9600);
 pinMode(2,OUTPUT);

}

void loop() 
{ if(Serial.available()>0)
  { 
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    
  if (data == '1')
  {
  digitalWrite(2,HIGH);
  delay(800);
  }
  if (data == '0')
  {
  digitalWrite(2,LOW);
  delay(800);
  }
  }
}
