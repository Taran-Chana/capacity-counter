#include <Arduino.h>
//Library created by Avishay Orpaz, used to output to the 4-digit 7-segment display
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3
#define PIR_1 7
#define PIR_2 8
#define LED 13

//variable setup
TM1637Display display(CLK, DIO);
//used for recieving input from the PIR sensors
int PIR_1_state = 0;
int PIR_2_state = 0;

//the value the the counter interacts with, initialized to 0
int counter = 0;

//the room capacity, should be changed to match use case
int capacity = 2;

//variables used for directional logic
int first = 0;
long wait = 0;

//initial arduino setup
void setup()
{
  //pin setup
  pinMode(PIR_1, INPUT);
  pinMode(PIR_2, INPUT);
  pinMode(LED, OUTPUT);
  //initial 4-digit display setup
  display.setBrightness(5);
  display.clear();
  display.showNumberDec(counter, false);

  //Serial Monitor Setup
  Serial.begin(9600);
  Serial.write("Started \n");
}

//capacity LED Logic, light up if capcity is met or reached
void update_cap_led()
{
  if(counter >= capacity) {
    digitalWrite(LED, HIGH);
  } 
  else{
    digitalWrite(LED, LOW);
  }
}

//increments count if passed true, decrements if false
//updates the display with new count, calls update_cap_led()
void update_count(bool inc)
{
  if(inc){
    counter++;
    display.clear();
    display.showNumberDec(counter, false);
    update_cap_led(); 
  } 
  else{
    counter--;
    if(counter < 0){
      counter = 0;
    }
    display.clear();
    display.showNumberDec(counter, false);
    update_cap_led();
  }
  //delay to wait for PIR sensors to reset 
  delay(1200);
}


void loop()
{
  //gets value from PIR sensors
  PIR_1_state = digitalRead(PIR_1);
  PIR_2_state = digitalRead(PIR_2);

  //used for directional logic
  wait++;

  if (PIR_1_state == HIGH){
    if(first == 0){
      first = 1;
      wait = 0;
    } 
    else if(first == 2){
      update_count(false);
      first = 0;
      wait = 0;
    }
  } 
  else if(PIR_2_state == HIGH) {
    if(first == 0){
      first = 2;
      wait = 0;
    }
    else if(first ==1){
      update_count(true);
      first = 0;
      wait = 0;
    }
  }
  
  //used to clean up situations where 1 PIR sensor receives an input but the other doesn't
  //meaning the person did not pass fully into the room and, therefore should not interact with the counter
  else
  { 
    if(wait > 50000){
      first = 0;
      wait = 0;
    }
      
  }

  //Incremental logging
  if(wait % 5000 == 0){
    Serial.print("first: ");
    Serial.print(first);
    Serial.print("  count: ");
    Serial.print(counter);
    Serial.print("  wait: ");
    Serial.print(wait);
    Serial.print("\n");
    }
  
}
