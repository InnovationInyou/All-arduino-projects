int state = 0;
void setup() {
  pinMode(7, OUTPUT);
   pinMode(9, OUTPUT);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  if(Serial.available() > 0)
  { 
    state = Serial.read(); // Reads the data from the serial port
 }
 if (state == '0') {
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(7, LOW);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(9, HIGH);// Turn LED OFF
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '1') {
  
  digitalWrite(7, LOW);
  delay(100);
  digitalWrite(9, LOW);
  delay(100);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(9, HIGH);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(9, HIGH);
  delay(100);
  Serial.println("LED: ON");;
  state = 0;
 } 
}
