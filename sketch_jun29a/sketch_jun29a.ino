 #include<SPI.h>
 #include<nRF24L01.h>
 #include<RF24.h>
 RF24 radio(7,8);//cns,ce
 const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}


void loop() { 
const char text0[] = "F";

radio.write(&text0, sizeof(text0));
delay(1000);

}
