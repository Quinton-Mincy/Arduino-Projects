defaut:
		avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o bareMetalCounter.o bareMetalCounter.c
		avr-gcc -mmcu=atmega328p bareMetalCounter.o -o bareMetalCounter
		avr-objcopy -O ihex -R .eeprom bareMetalCounter bareMetalCounter.hex
		avrdude -F -V -c arduino -p ATMEGA328P -P  /dev/cu.usbmodem14201 -b 115200 -U flash:w:bareMetalCounter.hex
