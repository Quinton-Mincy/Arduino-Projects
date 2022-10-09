#include <avr/io.h>
#include <util/delay.h>
 
#define BLINK_DELAY_MS 500
 
int main (void){
 /* set pin 5 of PORTB for output*/
 DDRD |= _BV(DDB2); //DDRB:Data Direction Register for PORTB.... _BV: bit value (of 8 bit number)
 DDRD |= _BV(DDB3);
 DDRD |= _BV(DDB4);
 DDRD |= _BV(DDB5);

 int binaryArray[][4] = {
                          {0,0,0,0},{0,0,0,PD5},{0,0,PD4,0},{0,0,PD4,PD5},{0,PD3,0,0},
                          {0,PD3,0,PD5},{0,PD3,PD4,0},{0,PD3,PD4,PD5},{PD2,0,0,0},{PD2,0,0,PD5},
                          {PD2,0,PD4,0},{PD2,0,PD4,PD5},{PD2,PD3,0,0},{PD2,PD3,0,PD5},{PD2,PD3,PD4,0},
                          {PD2,PD3,PD4,PD5}
                        };
int rounds = 3;
int index = 0;
DDRB |= _BV(DDB5);
PORTB |= _BV(PB5);
while(index < 1) {
  /* set pins 2-5 to 1 to turn LEDs on */
  int x = 0;
  int y = 0;
  while(x < 16){
    PORTD |= _BV(binaryArray[x][y]);
    y++;
    PORTD |= _BV(binaryArray[x][y]);
    y++;
    PORTD |= _BV(binaryArray[x][y]);
    y++;
    PORTD |= _BV(binaryArray[x][y]);
    y = 0;
    _delay_ms(BLINK_DELAY_MS);
    
    /* set pins 2-5 to zero to turn LEDs off */
    PORTD &= ~ _BV(binaryArray[x][y]);
    y++;
    PORTD &= ~ _BV(binaryArray[x][y]);
    y++;
    PORTD &= ~ _BV(binaryArray[x][y]);
    y++;
    PORTD &= ~ _BV(binaryArray[x][y]);
    y = 0;
    x++;
    _delay_ms(BLINK_DELAY_MS);
  }
  index++;
 }
 PORTB &= ~ _BV(PB5);
 return 0;
}
