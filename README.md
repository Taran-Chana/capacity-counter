# Capacity Counter
UB CSE 321 project, a Real-time embedded system that increments and decrements a counter when a person enters or exits a room. This value is compared against a set room capacity, alerting users if a room is at capacity.

The current sketch is [phase3](phase3/). The previous prototype, which only features logic for the counter to increment when the PIR sensor goes off, is found in [phase2](phase2/).

# Setup

### Hardware needed:
- Arduino UNO R3
- 2 HC-SR501 PIR Sensors
- TM-1637 4-Digit Clock Display
- LED Light & compatible resistor
- 20+ Wires
- Breadboard _(recommended)_ 

_If you want to test that the hardware you obtain is working correctly, there are tests for the components in the [/tests](tests/) directory of this repository_

### Software needed:
- Arduino IDE _(recommended)_
- TM1637 Library by Avishay Orpaz, used to output to the TM-1637 4-digit clock display

### Arduino to Component Connections:
TM-1637 4-Digit Clock Display:
- D2: CLK
- D3: DIO
- 3.5V: VCC
- GND: GND

PIR 1:
- D7: Output
- 5V: Power
- GND: GND

PIR 2:
- D8: Output
- 5V: Power
- GND: GND

LED:
-  D13:
-  GND: (via compatible resistor)

_For the PIR sensors and the LED, they can be connected to the Arduino via a breadboard. However, I encountered difficulties when connecting the TM-1637 display to the 5V power via the breadboard. Due to this, I recommend connecting the display VCC to the 3.5V port on the Arduino._

Before uploading the sketch to the Arduino, you should change the capacity value to the capacity of the room this will be set up for.

Once the components have been assembled and the most up-to-date sketch, [phase3](phase3/), has been uploaded you are ready to start using this project. 

### Layout:
- Place the PIR sensors parallel to each other, perpendicular to the entrance, with PIR1 further away
- Place the TM-1637 display facing away from the entrance
- _I recommend putting a sign by the capacity light, to let users know what the light means_

# Uses

Once the capacity counter has been set up and power is provided to the Arduino, the system will start running. Once running: 
- The counter will increment up as people enter the room
- The counter will decrement as people leave the room(when they pass by the sensor)
- The current count will be shown on the display
- If the count is at or above the room capacity, the LED will turn on. This will let people know to wait until they enter.
- Once the count returns to below the capacity the light will turn off.
  
The current version requires a connection from the Arduino to a computer for power and logs the current state to the serial monitor. To reset the system you must disconnect it from the computer and then reconnect. 

