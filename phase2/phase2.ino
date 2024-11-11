#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define PIR 7
#define CAP 13

TM1637Display display(CLK, DIO);
int counter = 0;
int sensorState = 0;

void setup()
{
  display.setBrightness(5);
  pinMode(PIR, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  display.clear();
  display.showNumberDec(counter, false);
}

void loop()
{
  sensorState = digitalRead(PIR);
  
  if (sensorState == HIGH) {
    counter++;
    display.clear();
    display.showNumberDec(counter, false);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1200);
  } else { 
    digitalWrite(LED_BUILTIN, HIGH);
  }

}
