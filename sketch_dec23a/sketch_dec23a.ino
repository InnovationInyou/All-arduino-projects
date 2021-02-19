void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);

}

void loop() {
  int statein = analogRead(A0);
  int state1 = map(statein,0,1023,0,180);
  Serial.print(state1);
  Serial.print('\n');
  }
