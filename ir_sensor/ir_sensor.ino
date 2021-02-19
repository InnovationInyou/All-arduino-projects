int input1= 0;
int input2= 1;
int LED= 13;
int IRsensor= 2;
void setup() {
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
Serial.print(9600);
}

void loop() {
  
if(digitalRead(2)==HIGH)   

{

digitalWrite(13, HIGH);   
Serial.println(input2);
}

else

{

digitalWrite(13, LOW);    

}
Serial.println(input1);
delay(1000);              

}
