#include<LiquidCrystal_I2C_Hangul.h>
#include<Wire.h>
#define CLK 4
#define DT 3
#define SW 2
int i =0;
int counter = 0;
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;
LiquidCrystal_I2C_Hangul lcd(0x3F,16,2);
void setup() {
   pinMode(13,OUTPUT);
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  lastStateCLK = digitalRead(CLK);
  lcd.setCursor(0, 0);
  lcd.print("PUMP DELAY SYS");
}

void loop() {
  currentStateCLK = digitalRead(CLK);

  
  if (currentStateCLK != lastStateCLK )
  {
    if (digitalRead(DT) == currentStateCLK)
    {
      counter ++;
    if (counter>15)
      counter = 15;
    } 
    else {
      counter --;
    if (counter<0)
      counter = 0;
    
    }
    Serial.print("PUMP DELAY SYS");
    Serial.println(counter);
    Serial.println("second");
  }
  lastStateCLK = currentStateCLK;

  int btnState = digitalRead(SW);
  if (btnState == LOW) {
    
    if (millis() - lastButtonPress > 50)
    {
      
      Serial.println("Delay is Set:");
      Serial.println(counter);
    lcd.setCursor(0, 0);
    lcd.print("Delay  is  Set:");
   lcd.setCursor(0, 1);
    lcd.print(counter);
    lcd.print("second");
    delay(5000);
    lcd.setCursor(0, 0);
    lcd.print("Pump  is Start");
      int Set = counter* 1000;
      digitalWrite(13,HIGH);
      delay(Set);
      digitalWrite(13,LOW);
      
    }
     lastButtonPress = millis();
  }

    lcd.setCursor(0, 0);
    lcd.print("PUMP DELAY SYS");
    lcd.setCursor(0, 1);
    lcd.print(counter);
    lcd.print("second");
    
  }




