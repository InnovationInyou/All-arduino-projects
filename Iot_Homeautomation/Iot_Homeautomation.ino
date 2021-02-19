int Lamp=5;
int received=0;
int Lamp_state=0;

void setup() {
 Serial.begin(9600);
 pinMode(Lamp,OUTPUT);
 

}

void loop() {
  if(Serial.available()>0)
{
  received=Serial.read();
}
if(Lamp_state== 0&& received=='1')
{
  digitalWrite(Lamp,HIGH);
  Serial.println('ON');
  Lamp_state=1;
  received=0;
}
if(Lamp_state== 1&& received=='0')
{
  digitalWrite(Lamp,LOW);
  Serial.println('Off');
  Lamp_state=0;
  received=0;
}
}
