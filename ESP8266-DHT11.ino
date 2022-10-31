#include "DHT.h"

#define DHTPIN 4        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
 
DHT dht(DHTPIN, DHTTYPE);
 
float h ;
float t;
 
void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();
 
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
  } else {
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C "));
  }
 
  delay(2000);
}
