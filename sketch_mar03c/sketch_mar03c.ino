int trigPin = 4;    
int echoPin = 5; 
int trigPin1 = 2;    
int echoPin1 = 3;    
long duration, cm; 
long duration1, cm1; 
void setup() {
    Serial.begin(9600);                                  
    pinMode(13, OUTPUT);  
    pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  
 duration = pulseIn(echoPin, HIGH);
  duration1 = pulseIn(echoPin1, HIGH);
 
  
  cm = (duration/2) / 29.1; 
  cm1 = (duration1/2) / 29.1;       
  Serial.print(cm);
  Serial.print("cm");
  Serial.print(cm1);
  Serial.print("cm1");
  Serial.println();
  delay(100);
  if (cm<100)
  {
    digitalWrite(13,HIGH);
    delay(5000);
     digitalWrite(13,LOW);
    delay(5000);
  }
  
}
