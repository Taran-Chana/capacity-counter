#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);


void setup()
{
  display.setBrightness(5);
}

void loop()
{

  display.clear();
  display.showNumberDec(25, false);
  delay(1500);
  display.clear();
  display.showNumberDec(65, false);
  delay(1500);
}
