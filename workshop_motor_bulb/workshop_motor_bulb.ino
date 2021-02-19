void setup() {
  pinMode(A0,INPUT);
   pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int IR;
  IR=analogRead(A0);
  Serial.println(IR);
  delay(1000);
if (IR>600)
{
digitalWrite(12,HIGH);
delay(1000);
 }
 if (IR<600)
{
digitalWrite(12,LOW);
delay(1000);
 }
}

