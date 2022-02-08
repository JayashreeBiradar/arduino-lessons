#include "DHT.h"
#define Type DHT11

int sensePin=2;
float tempC;
float tempF;
float humiDity;
int delayTime=1000;

DHT HT(sensePin,Type);

void setup() {
  Serial.begin(9600);
  HT.begin();
  delay(delayTime);
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  humiDity=HT.readHumidity(); 
  tempC=HT.readTemperature(); // Read temperature as Celsius (the default)
  tempF=HT.readTemperature(true); // Read temperature as Fahrenheit (isFahrenheit = true)

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   }
   
  Serial.print("Humidity:");
  Serial.print(humiDity);
  Serial.print("  Temerature C:");
  Serial.print(tempC);
  Serial.print("  Temperature F:");
  Serial.println(tempF);
  delay(delayTime);   // Wait a few seconds between measurements
} 
