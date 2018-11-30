
/**
  Sending device into deep sleep
*/
void goSleep(int minutes) {
  Serial.print("\t☾ Uaaah. I'm tired. Going back to bed for ");
  Serial.print(minutes);
  Serial.println(" minutes. Good night!\n");
  ESP.deepSleep(minutes * 60 * 1000000);
  delay(100);
}

void loopSleep() {
#ifdef ENABLE_DEEPSLEEP
  delay(500);
  goSleep(deepSleepMinutes);
#endif
}
