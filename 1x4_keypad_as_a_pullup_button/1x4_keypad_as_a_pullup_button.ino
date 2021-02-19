#define key1 42 //connect wire 1 to pin 2
#define key2 44 //connect wire 2 to pin 3
#define key3 38 //connect wire 3 to pin 4
#define key4 40 //connect wire 4 to pin 5

void setup() {
 Serial.begin(9600);
 pinMode(key1, INPUT_PULLUP);// set pin as input
 pinMode(key2, INPUT_PULLUP);// set pin as input
 pinMode(key3, INPUT_PULLUP);// set pin as input
 pinMode(key4, INPUT_PULLUP);// set pin as input   
}

void loop() {
  int key1S = digitalRead(key1);// read if key1 is pressed
  int key2S = digitalRead(key2);// read if key1 is pressed
  int key3S = digitalRead(key3);// read if key1 is pressed
  int key4S = digitalRead(key4);// read if key1 is pressed 
 // Code written for Robojax.com video Tutorial
     if(!key1S){
      Serial.println("key 1 is pressed");
     }
     if(!key2S){
      Serial.println("key 2 is pressed");
     }
     if(!key3S){
      Serial.println("key 3 is pressed");
     }
     if(!key4S){
      Serial.println("key 4 is pressed");
     }          
     delay(100);
}
