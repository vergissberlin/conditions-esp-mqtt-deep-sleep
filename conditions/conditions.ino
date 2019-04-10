/*
  Conditions

  MQTT bin project for coffee-bin https://coffee-bin-mqtt.readthedocs.io/

  The circuit:
    Input: Swtich for maintenance mode on pin XX to ground
    Input: Conditions bin attached to pin XX  from +3V
    10K resistor attached to pin 2 from ground
    Output: External LED to visualize the fill status on pin XX
    Output: Internal LED to visualize the maintance status on pin XX
    Output: Internal LED to visualize the wifi status on pin XX
    list the components attached to each input
    list the components attached to each output

  Created 11 September 2018
  By André Lademann <vergissberlin@gmail.com>

  https://github.com/vergissberlin/coffee-bin-mqtt
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
//#include "sleep.h"
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
  //client.publish("outTopic", payload);
  mqttPublish(payload);
}

void loop() {
  //loopSleep();
}
