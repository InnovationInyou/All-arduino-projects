void setup() {
  Serial.begin(9600);
 pinMode(8, OUTPUT); // put your setup code here, to run once:
 char data =0;
 }

void loop() {

 if(Serial.available()>0)
   {     
      data=Serial.read();
      if(data=='1'){
        digitalWrite(8,HIGH);
        
      }
        elseif(data=='0'){
          digitalWrite(8,LOW);
        }
      }
}
      
