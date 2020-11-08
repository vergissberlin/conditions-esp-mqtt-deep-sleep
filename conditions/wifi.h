/*
  Conditions
  By André Lademann <vergissberlin@gmail.com>

  https://github.com/vergissberlin/esp8266-mqtt-deep-sleep-dht
*/
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

int connectInteration = 0;
int connectInterationMaximum = 12;

void setupWifi(const String deviceId) {
  Serial.println(F("\n▶ WiFi"));
  Serial.print(F("Connecting to \""));
  Serial.print(wifiSsid);
  Serial.print(F("\"\t"));

  // WiFi.mode(WIFI_STA);
  WiFi.hostname(deviceId);
  WiFi.begin(wifiSsid, wifiPassword);

  while (WiFi.status() != WL_CONNECTED) {
    connectInteration++;
    connectInterationMaximum++;
    blinkError(pinLed, "", true);
    if (connectInteration == 12) {
      Serial.print("☉\n\t\t\t");
      connectInteration = 0;
    } else {
      Serial.print(F("☉"));
    }
    if (connectInterationMaximum == 12) {
      byte numSsid = WiFi.scanNetworks();
      Serial.print("SSID List:\t\t");
      Serial.println(numSsid);
      connectInteration = 12;
      delay(15000);
      ESP.restart();
    }
    delay(3000);
  }
  Serial.println();
  Serial.println(F("Status\t\tWiFi connected!"));
  Serial.print(F("IP address:\t"));
  Serial.println(WiFi.localIP());
  Serial.print("GW address:\t");
  Serial.println(WiFi.gatewayIP());
  Serial.print("MAC address:\t");
  Serial.println(WiFi.macAddress());
}
