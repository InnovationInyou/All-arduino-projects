#include <DigisparkOLED.h>
#include <Wire.h>
// ============================================================================

//#include "img0_128x64c1.h"
#include "digistump_128x64c1.h"


void setup() {
  // put your setup code here, to run once:

  oled.begin();

}

void loop() {
  
  // put your main code here, to run repeatedly:
  oled.fill(0xFF); //fill screen with color
  delay(1000);
  oled.clear(); //all black
  delay(1000);
  //usage: oled.setCursor(X IN PIXELS, Y IN ROWS OF 8 PIXELS STARTING WITH 0);
  oled.bitmap(0, 0, 128, 8, digistumplogo);
  delay(10000);
  oled.clear();
  oled.setFont(FONT8X16);
  oled.setCursor(40, 0);//wrap strings in F() to save RAM!
  oled.print(F("BRING"));
  oled.setCursor(8, 2);//wrap strings in F() to save RAM!
  oled.print(F("THE INNOVATION"));
  oled.setCursor(35, 4);//wrap strings in F() to save RAM!
  oled.print(F("IN YOU"));
  
  
  //oled.setFont(FONT6X8);
  //oled.print(F(" OLED!"));
  //oled.setCursor(0, 0); //two rows down because the 8x16 font takes two rows of 8
  //oled.println(F("test")); //println will move the cursor 8 or 16 pixels down (based on the front) and back to X=0
  //oled.print(F("test test test test test")); //lines auto wrap
  
  delay(5000);
  //usage oled.bitmap(START X IN PIXELS, START Y IN ROWS OF 8 PIXELS, END X IN PIXELS, END Y IN ROWS OF 8 PIXELS, IMAGE ARRAY);
  //oled.bitmap(0, 0, 128, 8, img0_128x64c1);
  //delay(3000);
  
}
