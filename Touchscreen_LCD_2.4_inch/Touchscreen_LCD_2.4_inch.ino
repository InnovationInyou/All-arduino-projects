#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define TS_MINX 214
#define TS_MINY 195
#define TS_MAXX 917  
#define TS_MAXY 914

#define YP A1
#define XM A2
#define YM 7
#define XP 6

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

boolean buttonEnabled = true;

void setup() {
  
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,WHITE);
  
  tft.setCursor(40,20);
  tft.setTextColor(BLACK);
  tft.setTextSize(6);
  tft.print("TFT LCD");
  
  tft.setCursor(65,80);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.print("Touchscreen");

   tft.setCursor(150,125);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("By");
  
  tft.setCursor(10,150);
  tft.setTextColor(BLACK);
  tft.setTextSize(3);
  tft.print("@Innovationin_you");
  
  tft.fillRoundRect(55,186, 220, 40,8,tft.color565(0, 0,255 ));//(red,green,blue)
  tft.drawRoundRect(55,186,220, 40,8,tft.color565(0,0,255) );  //(red,green,blue)
  tft.setCursor(80,200);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("    FOLLOW    ");

}

void loop() {
  TSPoint p = ts.getPoint();
  
  if (p.z > ts.pressureThreshhold) {
    
   p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
   p.y = map(p.y, TS_MAXY, TS_MINY, 0, 480);
       
   if(p.x>50 && p.x<260 && p.y>180 && p.y<270 && buttonEnabled){
    
    buttonEnabled = false;
    
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    
    tft.fillScreen(tft.color565(240,240,240));
    tft.drawRect(0,0,319,240,WHITE);
    tft.setCursor(45,20);
    tft.setTextColor(BLACK);
    tft.setTextSize(3);
    tft.print("    FIND\n\n       The\n\nINNOVATION IN YOU");
   }         
}
}
