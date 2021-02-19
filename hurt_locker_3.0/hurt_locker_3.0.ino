#include <Keypad.h>
 
char* secretCode = "1234";
int position = 0;
 
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte rowPins[rows] = {9,8,7,6};
byte colPins[cols] = {5,4.3,2};
 
Keypad keypad = Keypad(makeKeymap(keys),
                       rowPins, colPins,
                       rows, cols);
 
int redPin = 10;

 
void setup()
{
  pinMode(redPin, OUTPUT);
  
  
}
 
void loop()
{
  char key = keypad.getKey();
  if (key == '*' || key == '#') {
    position = 0;
    digitalWrite(redPin,HIGH);
    
  }
 
  if (key == secretCode[position]) {
    position++;
  }
 
  if (position == 4) {
    digitalWrite(redPin,LOW);
   
  }
  delay(50);
}
 

