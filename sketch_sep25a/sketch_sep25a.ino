#include <AccelStepper.h>
#include <Keypad.h>
#include <Wire.h>
#include<LiquidCrystal_I2C_Hangul.h>
LiquidCrystal_I2C_Hangul lcd(0x3F,16,2);
//User-defined values
volatile int firstnumber=99;    // used to tell how many numbers were entered
volatile int secondnumber=99;
volatile int thirdnumber=99;
volatile int fourthnumber=99;  
int keyfullnumber=0;
long receivedSteps = 0; //Number of steps
long receivedSpeed = 0; //Steps / second
long receivedAcceleration = 0; //Steps / second^2
char receivedCommand;
//-------------------------------------------------------------------------------
int directionMultiplier = 1; // = 1: positive direction, = -1: negative direction
bool newData, runallowed = false; // booleans for new data from serial, and runallowed flag
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
AccelStepper stepper(2, 2, 5);// direction Digital 9 (CCW), pulses Digital 8 (CLK)
void setup()
{
    lcd.init();                       // initialize the lcd 
    lcd.backlight();    
    Serial.begin(9600); //define baud rate
    lcd.setCursor(0, 0);
    lcd.print("ENTER COM:");
    Serial.println("Demonstration of AccelStepper Library"); //print a messages
    Serial.println("Send 'C' for printing the commands.");//setting up some default values for maximum speed and maximum acceleration
    Serial.println("Default speed: 400 steps/s, default acceleration: 800 steps/s^2.");
    stepper.setMaxSpeed(1500); //SPEED = Steps / second
    stepper.setAcceleration(400); //ACCELERATION = Steps /(second)^2
    stepper.disableOutputs(); //disable outputs
}
 
void loop()
{
    //Constantly looping through these 2 functions.
    //We only use non-blocking commands, so something else (should also be non-blocking) can be done during the movement of the motor
    
    RunTheMotor(); //function to handle the motor  
    keysend();
}
 
 
void RunTheMotor() //function for the motor
{
    if (runallowed == true)
    {
        stepper.enableOutputs(); //enable pins
        stepper.run(); //step the motor (this will step the motor by 1 step at each loop)  
    }
    else //program enters this part if the runallowed is FALSE, we do not do anything
    {
        stepper.disableOutputs(); //disable outputs
        return;
    }
}

void keysend(){
  
char keypressed = keypad.getKey(); // Get value of keypad button if
   if (keypressed != NO_KEY){ 
       newData = true;
      if (newData == true) {
       
       switch (keypressed) {
        
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

       case 'A':
       forArotationcalculation();
       break;

       case 'B':
       forBrotationcalculation();
       break;

       case 'C':
       Homing();
       break;

       case 'D':
       positionupdate();
       break;

       case '*':
       deletenumber();
       break;

       case '#':
       Stop();
       break;

       default:  

       break;
    }
   }
  newData = false;
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

void forArotationcalculation() { // Used to create a full number from entered

if (thirdnumber == 99 && secondnumber == 99 && firstnumber != 99) {

       keyfullnumber=firstnumber;
       forA(keyfullnumber);
}

if (secondnumber != 99 && thirdnumber == 99) {
      
       keyfullnumber=(firstnumber*10)+secondnumber;
       forA(keyfullnumber);
}

if (thirdnumber != 99){
  
       keyfullnumber=(firstnumber*100)+(secondnumber*10)+thirdnumber;
       forA(keyfullnumber);
  }
     resetnumbers(); // Reset numbers to get ready for new entry
}
void forA(int z) { // Move the stepper

      int A =map(z, 1, 88, 6400, 563200);
      directionMultiplier = 1; //We define the direction
      String currentpositionA = String(z);
      runallowed = true; //allow running - this allows entering the RunTheMotor() function.
      stepper.setMaxSpeed(1500); //set speed
      stepper.move(directionMultiplier * A);
      lcd.init();
      lcd.setCursor(0, 0);
      lcd.print("ENTER COM:");
      lcd.setCursor(0, 1);
      lcd.print("Moving :");
      lcd.setCursor(11, 1);
      lcd.print(currentpositionA);
      lcd.setCursor(14, 0);
      lcd.print("cm");
      lcd.setCursor(14, 1);
      lcd.print("cm");
  }

void forBrotationcalculation() { // Used to create a full number from entered

if (thirdnumber == 99 && secondnumber == 99 && firstnumber != 99) {

       keyfullnumber=firstnumber;
       forB(keyfullnumber);
}

if (secondnumber != 99 && thirdnumber == 99) {
      
       keyfullnumber=(firstnumber*10)+secondnumber;
       forB(keyfullnumber);
}

if (thirdnumber != 99){
  
       keyfullnumber=(firstnumber*100)+(secondnumber*10)+thirdnumber;
       forB(keyfullnumber);
  }
     resetnumbers(); // Reset numbers to get ready for new entry
}
void forB(int e) { // Move the stepper

      int B =map(e, 1, 88, 6400, 563200);
      directionMultiplier = -1; //We define the direction
      String currentpositionB = String(e);
      runallowed = true; //allow running - this allows entering the RunTheMotor() function.
      stepper.setMaxSpeed(1500); //set speed
      stepper.move(directionMultiplier * B);
      lcd.init();
      lcd.setCursor(0, 0);
      lcd.print("ENTER COM:");
      lcd.setCursor(0, 1);
      lcd.print("Moving :");
      lcd.setCursor(11, 1);
      lcd.print(currentpositionB);
      lcd.setCursor(14, 0);
      lcd.print("cm");
      lcd.setCursor(14, 1);
      lcd.print("cm");
  }
 
void Homing(){
      resetnumbers();
      runallowed = true;
      GoHome();// Run the function
      lcd.init();
      lcd.setCursor(0, 0);
      lcd.print("ENTER COM:");
      lcd.setCursor(0, 1);
      lcd.print("Moving :");
      lcd.setCursor(14, 0);
      lcd.print("cm");
      lcd.setCursor(14, 1);
      lcd.print("cm");
}

void GoHome()
{  
    if (stepper.currentPosition() == 0)
    {
        stepper.disableOutputs(); //disable power
    }
    else
    {
        stepper.setMaxSpeed(1500); //set speed manually to 400. In this project 400 is 400 step/sec = 1 rev/sec.
        stepper.moveTo(0); //set abolute distance to move
    }
}

void positionupdate(){
  
      resetnumbers();
      runallowed = false; //we still keep running disabled
      stepper.disableOutputs(); //disable power
      stepper.setCurrentPosition(0); //Reset current position. "new home"            
      lcd.init();
      lcd.setCursor(0, 0);
      lcd.print("ENTER COM:");
      lcd.setCursor(0, 1);
      lcd.print("Moving :");
      lcd.setCursor(14, 0);
      lcd.print("cm");
      lcd.setCursor(14, 1);
      lcd.print("cm");
}
void resetnumbers() { // Reset numbers for next entry
    
    firstnumber=99;
    secondnumber=99;
    thirdnumber=99;
    fourthnumber=99; 
}

void Stop(){
    resetnumbers();
    stepper.stop(); //stop motor
    stepper.disableOutputs(); //disable power
    runallowed = false; //disable running
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.print("ENTER COM:");
    lcd.setCursor(0, 1);
    lcd.print("Moving :");
    lcd.setCursor(14, 0);
    lcd.print("cm");
    lcd.setCursor(14, 1);
    lcd.print("cm");
}
void drawnokiascreen(String y) {
          lcd.init();
          lcd.setCursor(0, 0);
          lcd.print("ENTER COM:");
          lcd.setCursor(11, 0);
          lcd.print(y); // Redraw Nokia lcd
          lcd.setCursor(0, 1);
          lcd.print("Moving :");
          lcd.setCursor(14, 0);
          lcd.print("mm");
          lcd.setCursor(14, 1);
          lcd.print("mm");
 }
