void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600); 
}

void loop() {
  int IR;
  IR=analogRead(A0);
  Serial.println(IR);
  delay(1000);
}

