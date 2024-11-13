#include <Arduino.h>
//Library created by Avishay Orpaz, used to output to the 4-digit 7-segment display
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
  
  pinMode(PIR, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  //initial 4-digit display setup
  display.setBrightness(5);
  display.clear();
  display.showNumberDec(counter, false);
}

void loop()
{
  sensorState = digitalRead(PIR);
  //if PIR sensor detects motion
  if (sensorState == HIGH) {
    //increment counter & update display
    counter++;
    display.clear();
    display.showNumberDec(counter, false);
    digitalWrite(LED_BUILTIN, LOW);
    //delay added so counter only increments by 1
    delay(1200);
  } 
  //motion not detected
  else { 
    digitalWrite(LED_BUILTIN, HIGH);
  }

}
