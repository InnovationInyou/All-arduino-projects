
#define LED_MP3         A6            // MP3 LED (Green)

boolean         ledState = HIGH;
const long      blinkrate = 1000;

void setup() {


pinMode(LED_MP3, OUTPUT);

}

void loop() {
  digitalWrite(LED_MP3, ledState);
      
}
