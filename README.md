# Capacity Counter
UB CSE 321 project, a Real-time embedded system that increments and decrements on a person entering or exiting a room compared against a set room capacity, alerting users if a room is at capacity.

The current sketch is [phase3](phase3/). The previous prototype, which only features logic for the counter to increment when the PIR sensor goes off, is found in [phase2](phase2/).

# Setup

### Hardware needed:
- Arduino UNO R3
- 2 PIR Sensors
- 7-segment clock display
- LED Light & capable resistor
- 20+ Wires
- Breadboard _(recommended)_ 

_If you want to test that the hardware you obtain is working correctly, there are tests for the components in the [/tests](tests/) directory of this repository_

### Software needed:
- Arduino IDE _(recommended)_
- TM1637 Library by Avishay Orpaz, used to output to the 4-digit 7-segment display

### Arduino Connections:
7-Segment Clock Display
- 2: CLK
- 3: DIO
- 3.5V: VCC
- GND: GND

PIR 1
- 7: Output
- 5V: Power
- GND: GND

PIR 2
- 8: Output
- 5V: Power
- GND: GND

LED
-  13:
-  GND: (via compatible resistor)

_For the PIR sensors and the LED, they can be connected to the Arduino via a breadboard. However, I encountered difficulties when connecting the 7-segment display to the 5V power via the breadboard. Due to this, I recommend connecting the display VCC to the 3.5V port on the Arduino._

Before uploading the sketch to the Arduino, you should change the capacity value to the capacity of the room this will be set up for.

Once the components have been assembled and the most up-to-date sketch, [phase3](phase3/), has been uploaded you are ready to start using this product. Place the PIR sensors parallel to each other in front of the entrance where you want to manage capacity with the first sensor further away. I recommend putting a sign by the capacity light, to let users know what the light means.

# Uses

Once the capacity counter has been set up and power is provided to the Arduino, the system will start running. Once running the counter will increment up as people enter the room, and decrement as people leave the room(when they pass by the sensor). The current count will be shown on the display. If the count is at or above the room capacity, the LED will turn on. This will let people know to wait until they enter. Once the count returns to below the capacity the light will turn off. The current version requires a connection from the Arduino to a computer for power and logs the current state to the serial monitor. To reset the system you must disconnect it from the computer and then reconnect. 

