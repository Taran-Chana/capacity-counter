# Setup

## The hardware needed for this product is:
- Arduino UNO R3
- 2 PIR Sensors
- 7-segment clock display
- LED Light & capable capacitor
- Breadboard and Wires

_If you want to test the hardware you obtain is working correctly, there are [tests](tests/) for the components in the tests directory of this repository_
##
Arduino IDE is recommended to upload the code to Arduino.

## When connecting and assembling you need to make sure to use the following outputs on the Arduino
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
-  GND: (via capacitor)

_For the PIR sensors and the LED, they can be connected to the Arduino via a breadboard. However, I encountered difficulties when connecting the 7-segment display to the 5V power via the breadboard. Due to this, I recommend connecting the display VCC to the 3.5V port on the Arduino._

I recommended changing the value of the capacity, before uploading the sketch to fit the room this will be set up for.

# Uses

Once the components have been assembled and the most up-to-date sketch, phase 3, has been uploaded you are ready to start using this product. Place the PIR sensors parallel to each other in front of the entrance where you want to manage capacity with the first sensor further away. Once running the counter will increment up as people enter the room, and decrement as people leave the room(when they pass by the sensor). The current count will be shown on the display. If the count is at or above the room capacity, the LED will turn on. This will let people know to wait until they enter. I recommend adding a sign next to this light to make this more clear. Once the count returns to below the capacity the light will turn off.
