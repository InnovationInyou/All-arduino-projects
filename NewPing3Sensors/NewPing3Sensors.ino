// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define SONAR_NUM 4      // Number of sensors.
#define MAX_DISTANCE 400 // Maximum distance (in cm) to ping.

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
   NewPing(2, 3, MAX_DISTANCE),
   NewPing(4, 5, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(6, 7, MAX_DISTANCE), 
  NewPing(8, 9, MAX_DISTANCE)
};

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() { 
  digitalWrite(13,LOW);
  for (uint8_t i = 0; i < SONAR_NUM; i++)
  { // Loop through each sensor and display results.
    delay(1); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    Serial.print(i);
    Serial.print("=");
    Serial.print(sonar[i].ping_cm());
    Serial.print("cm ");
  if (sonar[i].ping_cm()<=50)
  {
    digitalWrite(13,HIGH);
    delay(5000);
  }  
  }
  Serial.println();
}
