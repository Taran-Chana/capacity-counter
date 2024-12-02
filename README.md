# Capacity Counter
UB CSE 321 project, a Real-time embedded system that increments and decrements on a person entering or exiting a room compared against a set room capacity, alerting users if a room is at capacity.


# Setup

### Hardware needed:
- Arduino UNO R3
- 2 PIR Sensors
- 7-segment clock display
- LED Light & capable capacitor
- X Wires
- Breadboard _(recommended)_ 

_If you want to test that the hardware you obtain is working correctly, there are [tests](tests/) for the components in the tests directory of this repository_

Arduino IDE is recommended to upload the code to Arduino.

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

Once the components have been assembled and the most up-to-date sketch, phase 3, has been uploaded you are ready to start using this product. Place the PIR sensors parallel to each other in front of the entrance where you want to manage capacity with the first sensor further away. I recommend putting a sign by the capacity light, to let users know what the light means.

# Uses

 Once running the counter will increment up as people enter the room, and decrement as people leave the room(when they pass by the sensor). The current count will be shown on the display. If the count is at or above the room capacity, the LED will turn on. This will let people know to wait until they enter. Once the count returns to below the capacity the light will turn off.

Once the capacity counter has been set up and power is provided to the Arduino 
