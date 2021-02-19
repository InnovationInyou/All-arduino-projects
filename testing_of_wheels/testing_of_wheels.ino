void setup() {
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
   digitalWrite(5,HIGH);
    digitalWrite(4,LOW);



}
