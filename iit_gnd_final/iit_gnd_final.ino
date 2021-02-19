#include <AccelStepper.h> // AccelStepper Library
#include <Keypad.h>      // Keypad Library
#include <Wire.h>
#include<LiquidCrystal_I2C_Hangul.h>
LiquidCrystal_I2C_Hangul lcd(0x3F,16,2);


volatile int firstnumber=99;    // used to tell how many numbers were entered
volatile int secondnumber=99;
volatile int thirdnumber=99;   // Variables to hold Distance and CurrentPosition

int keyfullnumber=0;          // used to store the final calculated distance value
String currentposition = ""; // Used for display on Nokia LCD

const byte ROWS = 4;  // Four Rows
const byte COLS = 4; // Four Columns
char keys[ROWS][COLS] = 
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {22, 24, 26, 28};  // Arduino pins connected to the row
byte colPins[COLS] = {30, 32, 34, 36}; // Arduino pins connected to the
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );// Keypad Library definition


AccelStepper stepper(2, 2, 5); // 1 = Easy Driver interface

void setup(){
         
   lcd.init();                       // initialize the lcd 
   lcd.backlight();        // AccelStepper speed and acceleration setup
   stepper.setMaxSpeed(1500);    // Not to fast or you will have missed steps
   stepper.setAcceleration(400); // Same here
   Serial.begin(9600);
  
   lcd.setCursor(0, 0);
   lcd.print("ENTER DIST:");
   lcd.setCursor(0, 1);
   lcd.print("CURRENT PO:");
   lcd.setCursor(14, 0);
   lcd.print("mm");
   lcd.setCursor(14, 1);
   lcd.print("mm");
 }


void loop(){
  
char keypressed = keypad.getKey(); // Get value of keypad button if
   if (keypressed != NO_KEY){ // If keypad button pressed check which key
     switch (keypressed) 
   {
       case '1':
       checknumber(1);
       break;

          case '2':
          checknumber(2);
          break;

          case '3':
          checknumber(3);
          break;

       case '4':
       checknumber(4);
       break;

 case '5':
 checknumber(5);
 break;

    case '6':
    checknumber(6);
    break;

          case '7':
          checknumber(7);
          break;

       case '8':
       checknumber(8);
       break;

   case '9':
   checknumber(9);
   break;

    case '0':
    checknumber(0);
    break;

       case '*':
       deletenumber();
       break;

    case '#':
    calculatedistance();
    break;
  }
 }
}

void checknumber(int x){
  
if (firstnumber == 99) { // Check if this is the first number entered
     
     firstnumber=x;
     String displayvalue = String(firstnumber); // Transform int to a
     drawnokiascreen(displayvalue);            // Redraw Nokia lcd
}
else {
  
if (secondnumber == 99) { // Check if it's the second number entered
     
     secondnumber=x;
     String displayvalue = (String(firstnumber) + String(secondnumber));
     drawnokiascreen(displayvalue); // Redraw Nokia lcd
} 
else{ // It must be the 3rd number entered
       
       thirdnumber=x;
       String displayvalue = (String(firstnumber) + String(secondnumber) +String(thirdnumber));
       drawnokiascreen(displayvalue); // Redraw Nokia lcd
  }
 }
}

void deletenumber() { // Used to backspace entered numbers

if (thirdnumber !=99) {
        
        String displayvalue = (String(firstnumber) + String(secondnumber));
        drawnokiascreen(displayvalue); // Redraw Nokia lcd
        thirdnumber=99;
}
else {
  
if (secondnumber !=99) {
       
        String displayvalue = String(firstnumber);
        drawnokiascreen(displayvalue); // Redraw Nokia lcd
        secondnumber=99;
}
else{
  
if (firstnumber !=99) {
        
        String displayvalue = "";
        drawnokiascreen(displayvalue); // Redraw Nokia lcd
        firstnumber=99;
   }
  }
 }
}

void calculatedistance() { // Used to create a full number from entered

if (thirdnumber == 99 && secondnumber == 99 && firstnumber != 99) {

       keyfullnumber=firstnumber;
       movestepper(keyfullnumber);
}

if (secondnumber != 99 && thirdnumber == 99) {
      
       keyfullnumber=(firstnumber*10)+secondnumber;
       movestepper(keyfullnumber);
}

if (thirdnumber != 99){
  
       keyfullnumber=(firstnumber*100)+(secondnumber*10)+thirdnumber;
       movestepper(keyfullnumber);
  }
     resetnumbers(); // Reset numbers to get ready for new entry
}

void movestepper(int z) { // Move the stepper

      unsigned long int cal=z*6400/10; // 800 steps per revolution (.5cm)
      stepper.runToNewPosition(cal);
      currentposition = String(z);
     lcd.init();
       
          lcd.setCursor(0, 0);
          lcd.print("ENTER DIST:");
          lcd.setCursor(0, 1);
          lcd.print("CURRENT PO:");
          lcd.setCursor(11, 1);
          lcd.print(currentposition);
          lcd.setCursor(14, 0);
          lcd.print("mm");
          lcd.setCursor(14, 1);
          lcd.print("mm");
  }
 

void resetnumbers() { // Reset numbers for next entry
    
    firstnumber=99;
    secondnumber=99;
    thirdnumber=99;
}

void drawnokiascreen(String y) {
      lcd.init();
      
          lcd.setCursor(0, 0);
          lcd.print("ENTER DIST:");
          lcd.setCursor(11, 0);
          lcd.print(y); // Redraw Nokia lcd
          lcd.setCursor(0, 1);
          lcd.print("CURRENT PO:");
          lcd.setCursor(11, 1);
          lcd.print(currentposition);
          lcd.setCursor(14, 0);
          lcd.print("mm");
          lcd.setCursor(14, 1);
          lcd.print("mm");
 
}
