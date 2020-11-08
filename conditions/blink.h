/*
  Conditions
  By André Lademann <vergissberlin@gmail.com>

  https://github.com/vergissberlin/esp8266-mqtt-deep-sleep-dht
*/

uint8_t statusHigh = HIGH;
uint8_t statusLow = LOW;

/**
   Invert state value
   œreturn LOW if the given value is HIGH, else HIGH if the given value is LOW
*/
uint8_t invertState(uint8_t value) {
  if ( value == LOW) {
    return HIGH;
  }  else {
    return LOW;
  }
}

/**
   Invert states values
   œreturn LOW if the given value is HIGH, else HIGH if the given value is LOW
*/
void invertStates(uint8_t value) {
  statusHigh = LOW;
  statusLow = HIGH;
}

void blinkError(int pin, char* message = "", boolean invert = false) {
  if (invert == true) invertStates;

  for (int i = 0; i <= 3; i++) {
    digitalWrite(pin, LOW);
    delay(60);
    digitalWrite(pin, HIGH);
    delay(30);
  }

  if (message != "") {
    Serial.println(message);
  }
}


void blinkInfo(int pin, char* message = "", boolean invert = true) {
  if (invert == true) invertStates;

  for (int i = 0; i <= 3; i++) {
    digitalWrite(pin, LOW);
    delay(600);
    digitalWrite(pin, HIGH);
    delay(400);
  }

  if (message != "") {
    Serial.println(message);
  }
}
