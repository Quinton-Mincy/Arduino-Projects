#include <Arduino.h>

int main(int argc, char** argc){
  int redLED = 2;
  int greenLED =3;
  int blueLED = 4;
  int whiteLED = 5;


  void setup() {
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    pinMode(whiteLED, OUTPUT);
  }
  //0-15 in 4 bit binary numbers
  int binaryArray[][4] = {
                            {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},
                            {0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1},
                            {1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},
                            {1,1,1,1}
                          };
  int binCounter = 0;
  int rounds = 50;
  int index = 0;
  void binCount() {
    while(index < rounds){
      //turn all LEDs on at beggining of round
      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,HIGH);
      digitalWrite(blueLED,HIGH);
      digitalWrite(whiteLED,HIGH);
      delay(1000);

      int x = 0;
      int y = 0;
      while(x < 16){
        digitalWrite(redLED, binaryArray[x][y]);
        y++;
        digitalWrite(greenLED, binaryArray[x][y]);
        y++;
        digitalWrite(blueLED, binaryArray[x][y]);
        y++;
        digitalWrite(whiteLED, binaryArray[x][y]);
        y = 0;
        x++;
        delay(750); //ms
      }
      index++;
    }
    //turn off LEDs at program end
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,LOW);
    digitalWrite(blueLED,LOW);
    digitalWrite(whiteLED,LOW);
    }
  return 0;
}
