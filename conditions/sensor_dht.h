/*
  Conditions
  By André Lademann <vergissberlin@gmail.com>

  REQUIRES the following Arduino libraries:
   - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
   - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
*/
#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);

void setupDHT() {
  Serial.println(F("\n▶ DHT sensor"));
  dht.begin();
  delay(3000);
}

float getTemperature(void) {
  // Get values from DHT
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature)) {
    Serial.println(F("Failed to read temperature from DHT sensor!"));
    return 0;
  }
  Serial.println("Temperature:\t" + String(temperature) + " °C");
  
  return temperature;
}


float getHumidity(void) {
  // Get values from DHT
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity)) {
    Serial.println(F("Failed to read humidity from DHT sensor!"));
    return 0;
  } 
  Serial.println("Humidity:\t" + String(humidity) + " %H");
 
  return humidity;
}
