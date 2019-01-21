/*
  Conditions

  MQTT bin project for coffee-bin https://coffee-bin-mqtt.readthedocs.io/

  Created 11 September 2018
  By André Lademann <vergissberlin@gmail.com>

  https://github.com/vergissberlin/coffee-bin-mqtt
*/

void setupPin() {
  pinMode(pinLed, OUTPUT);
}

void loopPin() {
  digitalWrite(pinLed, LOW);  
  delay(600);
  digitalWrite(pinLed, HIGH);
  delay(600);
}
