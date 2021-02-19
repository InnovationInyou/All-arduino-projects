void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
   unsigned int servo1= analogRead(A0);
   if(servo1>10 && servo1<171)
   {
    Serial.write('A');
    Serial.println("\n");
   }

}
