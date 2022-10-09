# Arduino Bare-Metal Projects
Introductory Projects For The Arduino Uno
***


Circuit Diagram Build: https://www.circuit-diagram.org/


## Circuit Diagram
Basic diagram of the Arduino Circuitry. Wires with color represent positive current from the Arduino to the LEDs, black wires represent connection to ground. Used 330 ohm resistors. Source is 5 volts.

![circuit (1)](https://user-images.githubusercontent.com/73136662/194449880-81a63608-5ffd-4860-87da-6cc66a802116.png)

## The Code

We will start by comparing the two versions of the Binary counter project: the "bare metal" version which utilizes the AVR LibC library for Atmel AVR 8-bit RISC microcontrollers (https://www.nongnu.org/avr-libc/), and the more abstracted version which uses the built in functionality of the Arduino IDE (official Arduino documentation: https://www.arduino.cc/reference/en/). Arduino's programming langauge is based on the AVR libraries. Comparing the opening lines of the two examples (Arduino IDE on left), we can see similarites between the two programs.

![Screen Shot 2022-10-08 at 11 07 51 PM](https://user-images.githubusercontent.com/73136662/194735922-b7c141aa-510a-446e-96e9-c8a6e2a35df5.png)

The pinMode funciton takes 2 arguments: pin and mode (makes sense, right!?). The pin argument, an int, denotes which i/o pin on the Arduino board that will be read from/written to. The mode argument describes what action that pin will take during the program (usually INPUT or OUTPUT). Accomplishing the same task, the DDRD macro, representing for the "Data Direction Register" for port D is performing a bit-wise OR operation (https://en.wikipedia.org/wiki/Bitwise_operations_in_C) to determine the data direction of the port pins (input/output). The DDB2-5 macros are bit numbers that the _BV macro is performing a bit-wise left-shift operation on. 

http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf

Two functions are used in this program: pinMode and digitatWrite (official Arduino documentation: https://www.arduino.cc/reference/en/). The void loop() and void() setup functions are expected in each arduino program. Void setup() is mainly used for pinModes, to declare variables, and to load in libraries. Void loop() is where the main program is executed. Download Arduino IDE: https://www.arduino.cc/en/software

#### digitalWrite
The digitalWrite function 2 arguments: the first being the pin on the arduino board to access, and the second being a boolean (HIGH or LOW), which tells the arduino to provide an electrical input to the pin (HIGH) or to provide no electrical input to the pin (LOW).



