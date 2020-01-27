#include "segDisplay.h"

/*
 * Devices used during tests :
 *  - 1 x Arduino Nano V3
 *  - 7 x 220 Ohms resistors
 *  - 1 x com. cathode 7-segment (FJ11001AH)
 *      
 *      Arduino pins  |   7 segment display (pin 1 bottom left)
 *      D5            |   7
 *      D6            |   6
 *      D7            |   4
 *      D8            |   2
 *      D9            |   1
 *      D10           |   9
 *      D11           |   10
 *                    |   3 : GND
 *                    |   8 : GND
 */

segDisplay displ = segDisplay(5, 6, 7, 8, 9, 10, 11);

void setup() {
  displ.setup();
}

void loop() {
  //display all numbers from 0 to 9 (for 0.5s each)
  for(int i=0 ; i<10 ; i++){
    displ.display(i);
    delay(500);
  }

  //turn off the screen for 1s
  displ.noDisplay();
  delay(1000);

}
