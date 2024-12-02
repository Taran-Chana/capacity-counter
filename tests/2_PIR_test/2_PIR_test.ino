//Test 2 PIR sensors
//outputs to display which 
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define PIR_1 7
#define PIR_2 8


TM1637Display display(CLK, DIO);
int PIR_1_state = 0;
int PIR_2_state = 0;

void setup()
{
  
  pinMode(PIR_1, INPUT);
  pinMode(PIR_2, INPUT);

  display.setBrightness(5);
  display.clear();
}

void loop()
{
  PIR_1_state = digitalRead(PIR_1);
  PIR_2_state = digitalRead(PIR_2);
  
  if (PIR_1_state == HIGH){
    display.clear();
    display.showNumberDec(1, false);
    delay(1200);
  } else if(PIR_2_state == HIGH) {
    display.clear();
    display.showNumberDec(2, false);
    delay(1200);
  } else
  {
    display.clear();
    display.showNumberDec(0, false);
    delay(1200);
  }
}