
#include <Keypad.h>
char* secretCode = "235711";
int position = 0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int led = 13;
 

void setup(){
 pinMode(led, OUTPUT);
  setLocked(true);
  Serial.print(9600);
}
  
void loop(){
  char key = keypad.getKey();
  if (key == '*' || key == '#') {
    position = 0;
    setLocked(true);
  }
 
  if (key == secretCode[position]) {
    position++;
  }
 
  if (position == 6) {
    setLocked(false);
  }
  delay(50);
}
 
void setLocked(int locked)
{
  if (locked) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
