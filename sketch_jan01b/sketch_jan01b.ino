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
 }
