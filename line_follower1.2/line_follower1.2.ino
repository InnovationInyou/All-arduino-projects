void setup() {
  pinMode(3,INPUT);

  pinMode(4,INPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  
}

void loop() {
if (digitalRead(3)==HIGH,digitalRead(4)==HIGH){
digitalWrite(8,HIGH);
digitalWrite(12,HIGH);
}
if (digitalRead(3)==LOW){
digitalWrite(8,HIGH);
digitalWrite(12,LOW);
}
if (digitalRead(4)==LOW){
digitalWrite(12,HIGH);
digitalWrite(8,LOW);
}
if (digitalRead(2)==LOW,digitalRead(3)==LOW){
digitalWrite(8,LOW);
digitalWrite(12,LOW);
}

}

