void setup() {
 pinMode(6,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(9600);

}

void loop() {
  int pushbutton1 =digitalRead(6);
 if(pushbutton1==HIGH){
  Serial.print( 'F');
  Serial.print("\n");
  delay(1000);
 }
int pushbutton2 =digitalRead(9);
 if(pushbutton2==HIGH){
  Serial.print( 'B');
  Serial.print("\n");
  delay(1000);
 }
 int pushbutton3=digitalRead(10);
 if(pushbutton3==HIGH){
  Serial.print( 'L');
  Serial.print("\n");
  delay(1000);
 }
 int pushbutton4=digitalRead(11);
 if(pushbutton4==HIGH){
  Serial.print( 'R');
  Serial.print("\n");
  delay(1000);
 }


int variable1 =analogRead(A0);
if(variable1>10){
  int servo1=map(variable1,0,1023,1000,2000);
  Serial.print(servo1);
  Serial.print("\n");
  delay(1000);
}

int variable2 =analogRead(A1);
if(variable2>10){
  int servo2=map(variable2,0,1023,3000,4000);
  Serial.print(servo2);
  Serial.print("\n");
  delay(1000);
}


int variable3 =analogRead(A2);
if(variable3>10){
  int servo3=map(variable3,0,1023,5000,6000);
  Serial.print(servo3);
  Serial.print("\n");
  delay(1000);
}


int variable4 =analogRead(A3);
if(variable4>10){
  int servo4=map(variable4,0,1023,7000,8000);
  Serial.print(servo4);
  Serial.print("\n");
  delay(1000);
}


int variable5 =analogRead(A4);
if(variable5>10){
  int servo5=map(variable5,0,1023,9000,10000);
  Serial.print(servo5);
  Serial.print("\n");
  delay(1000);
}


int variable6 =analogRead(A5);
if(variable6>10){
  int servo6=map(variable6,0,1023,11000,12000);
  Serial.print(servo6);
  Serial.print("\n");
  delay(1000);
}
  }