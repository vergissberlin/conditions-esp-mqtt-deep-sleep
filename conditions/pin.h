/*
  Conditions
  By André Lademann <vergissberlin@gmail.com>

  https://github.com/vergissberlin/esp8266-mqtt-deep-sleep-dht
*/

void setupPin() {
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);  
  delay(600);
  digitalWrite(pinLed, HIGH);
  delay(600);
}

void loopPin() {
}
