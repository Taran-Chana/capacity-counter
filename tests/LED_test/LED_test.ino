#include <Arduino.h>

#define LED 13


void setup() {
  //pin setup
  pinMode(LED, OUTPUT);
}

void loop() {
  //test LED by flashing light on/off
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);

}
