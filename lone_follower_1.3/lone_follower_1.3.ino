
  void setup() {
  pinMode(2,INPUT);
  pinMode(5,INPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  
  
}

void loop() {
  if(digitalRead(2)==HIGH,digitalRead(5)==HIGH)
  digitalWrite(8,HIGH);
digitalWrite(12,HIGH);
if(digitalRead(2)==HIGH,digitalRead(5)==LOW)
digitalWrite(8,HIGH);
digitalWrite(12,LOW);
if(digitalRead(2)==LOW,digitalRead(5)==HIGH)
digitalWrite(8,LOW);
digitalWrite(12,HIGH);





}
