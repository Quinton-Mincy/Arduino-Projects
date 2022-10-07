# Arduino-Projects
Introductory Projects For The Arduino Uno
***
Arduino Library Files: https://github.com/arduino/ArduinoCore-avr/tree/master/cores/arduino

Download Arduino IDE: https://www.arduino.cc/en/software

Circuit Diagram Build: https://www.circuit-diagram.org/

Video Demonstration: https://youtu.be/cTuqyx6IGUA

## Circuit Diagram
Basic diagram of the Arduino Circuitry. Wires with color represent positive current from the Arduino to the LEDs, black wires represent connection to ground. Used 330 ohm resistors. Source is 5 volts.

![circuit (1)](https://user-images.githubusercontent.com/73136662/194449880-81a63608-5ffd-4860-87da-6cc66a802116.png)

## The Code
Two functions are used in this program: pinMode and digitatWrite (official Arduino documentation: https://www.arduino.cc/reference/en/). The void loop() and void() setup functions are expected in each arduino program. Void setup() is mainly used for pinModes, to declare variables, and to load in libraries. Void loop() is where the main program is executed. 

#### pinMode
The pinMode funciton takes 2 arguments: pin and mode (makes sense, right!?!). The pin argument, an int, denotes which pin on the Arduino board that will be read from/written to. The mode argument describes what action that pin will take during the program (usually INPUT or OUTPUT). 


