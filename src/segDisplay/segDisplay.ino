#include "segDisplay.h"

/*
 * Devices used during tests :
 *  - 1 x Arduino Nano V3 / Atmega328p-au
 *  - 7 x 220 Ohms resistors
 *  - 1 x com. cathode 7-segment (FJ11001AH)
 *      
 *      Arduino pins  |   Atmega328p-au   |   7 segment display (1 bottom left)
 *      --------------|-------------------|------------------------------------
 *      D5            |   9:PD5           |   e:1
 *      D6            |   10:PD6          |   d:2
 *      D7            |   11:PD7          |   c:4
 *      D8            |   12:PB0          |   b:6
 *      D9            |   13:PB1          |   a:7
 *      D10           |   14:PB2          |   f:9
 *      D11           |   15:PB3          |   g:10
 *                    |   3 : GND
 *                    |   8 : GND
 */

segDisplay displ = segDisplay(9, 8, 7, 6, 5, 10, 11);

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
