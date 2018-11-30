/*
  Conditions

  MQTT bin project for coffee-bin https://coffee-bin-mqtt.readthedocs.io/

  Created 11 September 2018
  By André Lademann <vergissberlin@gmail.com>

  https://github.com/vergissberlin/coffee-bin-mqtt
*/

// ************ Global State (you don't need to change this!) ******************

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_SERVERPORT, MQTT_USERNAME, MQTT_KEY);

// ****************************** Feeds *****************************************
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish mqttPublishTemperature  = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME MQTT_FEED_TEMPERATURE);
Adafruit_MQTT_Publish mqttPublishHumidity     = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME MQTT_FEED_HUMIDITY);

// *************************** Sketch Code **************************************

void MQTT_connect();

void MQTT_connect() {
  int8_t ret;
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.println("Connecting to MQTT \"" + String(MQTT_SERVER) + "\"");
  Serial.print(F("Status "));
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.print(F("Retrying MQTT connection in 5 seconds … "));
    mqtt.disconnect();
    delay(5000); // wait 5 seconds
    retries--;
    if (retries == 0) {
      while (1);
    }
  }
  Serial.println(F("MQTT Connected!\n"));
}

void mqttPinTemperature(double state) {
  if (! mqttPublishTemperature.publish(state)) {
    blinkError(pinLed, "MQTT temperature failed.", true);
  } else {
    Serial.print("\tTemperature: " + String(state) + " °C");
  }
}

void mqttPinHumidity(double state) {
  if (! mqttPublishHumidity.publish(state)) {
    blinkError(pinLed, "MQTT humidity failed.", true);
  } else {
    Serial.println("\tHumidity: " + String(state) + " %");
  }
}

void setupMqtt() {
  Serial.println(F("\n▶ MQTT"));
}

void loopMqtt() {
  MQTT_connect();
}
