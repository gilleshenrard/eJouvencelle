#include "CD4511.h"

/*
 * Devices used during tests :
 *  - 1 x Arduino Nano V3 / Atmega 328p-au
 *  - 1 x CD4511
 *  - 7 x 220 Ohms resistors
 *  - 1 x com. cathode 7-segment (FJ11001AH)
 * 
 * CD4511 library testing procedure
 * --------------------------------
 *      CD4511 pins   |   Arduino pins   |   Atmega328p-au
 *      --------------|------------------|----------------
 *      B   : 1       |   D5             |   9   : PD5
 *      C   : 2       |   D6             |   10  : PD6
 *      LT  : 3       |   +5V            |   +5V
 *      BL  : 4       |   D7             |   11  : PD7
 *      LE  : 5       |   D8             |   12  : PB0
 *      D   : 6       |   D9             |   13  : PB1
 *      A   : 7       |   D10            |   14  : PB2
 *      VSS : 8       |   GND            |   GND
 *      VDD : 16      |   +5V            |   +5V
 *      
 *      CD4511 pins   |   7 segment display (1 bottom left)
 *      --------------|------------------------------------
 *      e : 9         |   1
 *      d : 10        |   2
 *      c : 11        |   4
 *      b : 12        |   6
 *      a : 13        |   7
 *      g : 14        |   10
 *      f : 15        |   9
 *                    |   3 : GND
 *                    |   8 : GND
 */

CD4511 displ = CD4511(10, 5, 6, 9, 8, 7);

void setup() {
  displ.setup();
}

void loop() {
  //turn on the display
  displ.displayON();

  //display all numbers from 0 to 9 (for 0.5s each)
  for(int i=0 ; i<10 ; i++){
    displ.setNumber(i);
    displ.commit();
    delay(500);
  }

  //turn off the screen for 1s
  displ.displayOFF();
  delay(1000);
}
