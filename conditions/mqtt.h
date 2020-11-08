/*
  Conditions
  By André Lademann <vergissberlin@gmail.com>

  https://github.com/vergissberlin/esp8266-mqtt-deep-sleep-dht
*/
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

char mqttFeedWithId[200];

void setupMqtt(const uint32_t deviceId) {
  Serial.println(F("\n▶ MQTT"));
  char deviceIdChar[8];
  sprintf(deviceIdChar,"%lu", deviceId);

  // Connection
  client.setServer(mqttServer, mqttPort);
  client.connect(deviceIdChar, mqttUsername, mqttPassword, mqttWillTopic, mqttQos, mqttRetain, deviceIdChar);

  // Feeds generation
  snprintf(mqttFeedWithId, sizeof(mqttFeedWithId), mqttFeed, deviceIdChar);
  
  if(client.connected()) {
    Serial.print("MQTT connected:\t");
    Serial.println(client.state());
  } else {
    Serial.println("MQTT not connected");
  }
  client.loop();
}

/**
 * @see https://arduinojson.org/v6/faq/how-to-use-arduinojson-with-pubsubclient/
 */
void mqttPublish(char* value) {
  if (! client.publish(mqttFeedWithId, value)) {
    blinkError(pinLed, "MQTT failed.", true);
  } else {
    Serial.println("Data:\t\t" + String(value));
  }
}

int replaceChar(char *str, char orig, char rep) {
    char *ix = str;
    int n = 0;
    while((ix = strchr(ix, orig)) != NULL) {
        *ix++ = rep;
        n++;
    }
    return n;
}
