# Arduino Bare-Metal Projects - In Progress
Introductory Projects For The Arduino Uno
***


Circuit Diagram Build: https://www.circuit-diagram.org/


## Circuit Diagram
Basic diagram of the Arduino Circuitry. Wires with color represent positive current from the Arduino to the LEDs, black wires represent connection to ground. Used 330 ohm resistors. Source is 5 volts.

![circuit (1)](https://user-images.githubusercontent.com/73136662/194449880-81a63608-5ffd-4860-87da-6cc66a802116.png)

## The Code

We will start by comparing the two versions of the Binary counter project: the "bare metal" version which utilizes the AVR LibC library for Atmel AVR 8-bit RISC microcontrollers (https://www.nongnu.org/avr-libc/), and the more abstracted version which uses the built in functionality of the Arduino IDE (official Arduino documentation: https://www.arduino.cc/reference/en/). Arduino's programming langauge is based on the AVR libraries. Comparing the opening lines of the two examples (Arduino IDE on left), we can see similarites between the two programs.

![Screen Shot 2022-10-08 at 11 07 51 PM](https://user-images.githubusercontent.com/73136662/194735922-b7c141aa-510a-446e-96e9-c8a6e2a35df5.png)

The pinMode funciton takes 2 arguments: pin and mode (makes sense, right!?). The pin argument, an int, denotes which i/o pin on the Arduino board that will be read from/written to. The mode argument describes what action that pin will take during the program (usually INPUT or OUTPUT). Accomplishing the same task, the DDRD macro, representing for the "Data Direction Register" for port D is performing a bit-wise OR operation (https://en.wikipedia.org/wiki/Bitwise_operations_in_C) to determine the data direction of the port pins (input/output). The DDB2-5 macros are bit numbers that the _BV macro is performing a bit-wise left-shift operation on the binary number one with. Taking a look at the this particilar registers architecure: 

![Screen Shot 2022-10-08 at 11 23 31 PM](https://user-images.githubusercontent.com/73136662/194738315-dcb27950-7431-4d4c-bc72-a9e957e00779.png)

these four bit-wise operations result in the pins D2-D5 on the arduino board, corresponding to pins PD2-PD5 per the microproccessor's port architecure (discussed more in Hardware Architecture section), to be designated as output pins, accomplishing the same task as pinMode has done, but by interfacing directly with the hardware. 

The 2D matrix array in both code snippets are essentially the same, however, the bare metal version contains the bit numbers corresponding to the pins on the register, as opposed to the Arduino IDE code snippet which features only 0's and 1's, corresponding to HIGH and LOW, which we see in this code snippet:

![Screen Shot 2022-10-09 at 1 06 39 AM](https://user-images.githubusercontent.com/73136662/194739048-c5701b2e-7cc7-4a53-8c38-60d581cf01e7.png)

The digitalWrite function 2 arguments: the first being the pin on the arduino board to access, and the second being a boolean (HIGH or LOW), which tells the arduino to provide an electrical input to the pin (HIGH) or to provide no electrical input to the pin (LOW).

## Performance

From a memory standpoint, the bare metal version takes up half as much space! Minimizing memory usage is very important when working with microcontrollers, as there is not much space to begin with. 

![Screen Shot 2022-10-09 at 1 13 31 AM](https://user-images.githubusercontent.com/73136662/194739258-57766f04-7ee9-4ff1-8deb-c24ca3809f4e.png)

![Screen Shot 2022-10-09 at 1 09 40 AM](https://user-images.githubusercontent.com/73136662/194739184-5d6d9f84-11ed-485e-8a7d-d0d9b1dde774.png)

## Hardware Architecture
![Screen Shot 2022-10-09 at 12 56 14 AM](https://user-images.githubusercontent.com/73136662/194738783-1f6f266c-20de-4460-bf5a-20fdf96e20c7.png)



