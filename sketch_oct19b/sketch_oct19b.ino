void setup() {
  Serial.begin(9600);
}

void loop() {
 if (Serial.available()>=2)
  {
    unsigned int servopos=Serial.read();
    unsigned int servopos1=Serial.read();
    unsigned int realservo=(servopos1*256)+servopos;
    Serial.println(realservo);
    Serial.print("\n");
  }
}
