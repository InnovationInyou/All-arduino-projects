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
  Serial.print( "pushbutton1");
  Serial.print("\n");
 }

 int pushbutton2 =digitalRead(9);
 if(pushbutton2==HIGH){
  Serial.print( "pushbutton2");
  Serial.print("\n");
 }


 int pushbutton3 =digitalRead(10);
 if(pushbutton3==HIGH){
  Serial.print( "pushbutton3");
  Serial.print("\n");
 }

 int pushbutton4 =digitalRead(11);
 if(pushbutton4==HIGH){
  Serial.print( "pushbutton4");
  Serial.print("\n");
 }

 
 int variable1 =analogRead(A0);
 if(variable1>0){
 Serial.println("variable1=");
 Serial.print(variable1);
 Serial.print("\n");
}

int variable2 =analogRead(A1);
 if(variable2>0){
 Serial.println("variable2=");
 Serial.print(variable2);
 Serial.print("\n");
}


int variable3 =analogRead(A2);
 if(variable3>0){
 Serial.println("variable3=");
 Serial.print(variable3);
 Serial.print("\n");
}
int variable4 =analogRead(A3);
 if(variable4>0){
 Serial.println("variable4=");
 Serial.print(variable4);
 Serial.print("\n");
}

int variable5 =analogRead(A4);
 if(variable5>0){
 Serial.println("variable5=");
 Serial.print(variable5);
 Serial.print("\n");
}


int variable6 =analogRead(A5);
 if(variable6>0){
 Serial.println("variable6=");
 Serial.print(variable6);
 Serial.print("\n");
}
}
