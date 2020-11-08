/*
  Conditions
  By André Lademann <vergissberlin@gmail.com>

  https://github.com/vergissberlin/esp8266-mqtt-deep-sleep-dht
*/
#include <ArduinoJson.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// Load configuration
#include "config.h"

// Include libraries (order matters)
#include "blink.h"
#include "wifi.h"
#include "mqtt.h"
#include "pin.h"
#include "sleep.h"
#include "sensor_dht.h"


// Data storage
StaticJsonDocument<512> doc;

void setup() {
  Serial.begin(serialBautRate);
  while (!Serial) continue;
  
  Serial.println(F("\n\t✰✰✰  Conditions booting ✰✰✰ \n\n"));
  Serial.print("Device id: ");
  Serial.println(String(deviceId));

  setupWifi(String(deviceId));
  setupPin();
  setupMqtt(deviceId);
  setupDHT();
  
  doc["temperature"] = getTemperature();
  doc["humidity"] = getHumidity();
  
  char payload[512];
  serializeJson(doc, payload);
  mqttPublish(payload);
}

void loop() {
  loopSleep();
}
