# Arduino Bare-Metal Projects - In Progress
Introductory Projects For The Arduino Uno
***


Circuit Diagram Build: https://www.circuit-diagram.org/


## Circuit Diagram
Basic diagram of the Arduino Circuitry. Wires with color represent positive current from the Arduino to the LEDs, black wires represent connection to ground. Used 330 ohm resistors. Source is 5 volts.

![circuit (1)](https://user-images.githubusercontent.com/73136662/194449880-81a63608-5ffd-4860-87da-6cc66a802116.png)

## The Code

We will start by comparing the two versions of the Binary counter project: the "bare metal" version which utilizes the AVR LibC library for Atmel AVR 8-bit RISC microcontrollers (https://www.nongnu.org/avr-libc/), and the more abstracted version which uses the built in functionality of the Arduino IDE (official Arduino documentation: https://www.arduino.cc/reference/en/). Arduino's programming langauge is based on the AVR libraries. Comparing the opening lines of the two examples (Arduino IDE on left), we can see similarites between the two programs.

![Screen Shot 2022-10-10 at 6 17 42 PM](https://user-images.githubusercontent.com/73136662/194960655-c88faf93-59f5-4ab2-9f62-85051f409bb9.png)

The pinMode funciton takes 2 arguments: pin and mode (makes sense, right!?). The pin argument, an int, denotes which i/o pin on the Arduino board that will be read from/written to. The mode argument describes what action that pin will take during the program (usually INPUT or OUTPUT). Accomplishing the same task, the DDRD macro, representing for the "Data Direction Register" for port D is performing a bit-wise OR operation (https://en.wikipedia.org/wiki/Bitwise_operations_in_C) to configure the data direction of the pins on port D (input/output). The DD2-5 macros are correspond to the port pin numbers, and the _BV macro is performing a bit-wise left-shift operation on the binary number one by the inputs DD2-5 defined values (simply decimal numbers 2-5) shown here:

![Screen Shot 2022-10-10 at 5 23 57 PM](https://user-images.githubusercontent.com/73136662/194954603-3b4ba73f-0b5d-4f40-8191-a8ff772ebb4b.png)

Taking a look at the this particilar registers architecure: 

![Screen Shot 2022-10-08 at 11 23 31 PM](https://user-images.githubusercontent.com/73136662/194738315-dcb27950-7431-4d4c-bc72-a9e957e00779.png)

these four bit-wise operations result in the pins D2-D5 on the arduino board, corresponding to pins PD2-PD5 per the microproccessor's port architecure (discussed more in Hardware Architecture section), to be designated as output pins, accomplishing the same task as pinMode has done, but by interfacing directly with the hardware. 

The 2D matrix array in both code snippets are essentially the same, however, the bare metal version contains the port pin numbers corresponding to the pins on the register, as opposed to the Arduino IDE code snippet which features only 0's and 1's, corresponding to HIGH and LOW, which we see in this code snippet:

![Screen Shot 2022-10-09 at 1 06 39 AM](https://user-images.githubusercontent.com/73136662/194739048-c5701b2e-7cc7-4a53-8c38-60d581cf01e7.png)

The digitalWrite function 2 arguments: the first being the pin on the arduino board to access, and the second being a boolean (HIGH or LOW), which tells the arduino to provide an electrical input to the pin (HIGH) or to provide no electrical input to the pin (LOW). In the bare-metal program, we see PORTD, which expands to PORTD's port address, performing the same OR operation we saw before being performed on the DDR, but is now being performed to the port. In the first case, we were configuring the port pins to be output pins, and now we are actually turning them on. Direclty below this, we see an and operation being performed on the inverse of the original instruction (accomplished by the NOT operator), which turns the pins off. The Arduino IDE version does not not turn each pin off after each number is shown, only at the end of the number sequence by the digitalWrite(pinLocation, LOW) command. So, the bare-metal version, not including the extra work the IDE version does in compilation, is actually performing more computations.
## Performance

From a memory standpoint, the bare metal version (top image) takes up half as much space! Minimizing memory usage is very important when working with microcontrollers, as there is not much space to begin with. 

![Screen Shot 2022-10-09 at 1 13 31 AM](https://user-images.githubusercontent.com/73136662/194739258-57766f04-7ee9-4ff1-8deb-c24ca3809f4e.png)

![Screen Shot 2022-10-09 at 1 09 40 AM](https://user-images.githubusercontent.com/73136662/194739184-5d6d9f84-11ed-485e-8a7d-d0d9b1dde774.png)

## Hardware Architecture
![Screen Shot 2022-10-09 at 12 56 14 AM](https://user-images.githubusercontent.com/73136662/194738783-1f6f266c-20de-4460-bf5a-20fdf96e20c7.png)

As can be seen on the bottom right of the board, pins D2-D5 are the pins that were connected to the LED's for this project. After we desginated them as output pins, as discussed above, we then turned them on and off by setting the pins on port D's data register to either a 1 (on) or 0 (off):

![Screen Shot 2022-10-08 at 11 23 42 PM](https://user-images.githubusercontent.com/73136662/194960792-c444380a-b8a9-431a-9e53-f83b9c5180df.png)

To delve deeper into the hardware architecture, take a look at the datasheet for the ATMEGA 238p microprocessor (http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf). 

## Summary

In this project, we learned the basics of bitwise operations, the hardware architecture of the Arduinno board/ATMEGA 228p microprocessor, and the software architecture of the AVR LibC library. We compared the code of the Arduino and bare metal implementations of this project, and discovered that the Arduino IDE actually builds on top of the AVR LibC library, and uses bare metal instructions that we implemented in our bare metal program. 



