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
 *      B   : 1       |   A0             |   23  : PC0
 *      C   : 2       |   A1             |   24  : PC1
 *      LT  : 3       |   +3.3V          |   +3.3V
 *      BL  : 4       |   A2             |   25  : PC2
 *      LE  : 5       |   A3             |   26  : PC3
 *      D   : 6       |   A4             |   27  : PC4
 *      A   : 7       |   A5             |   28  : PC5
 *      VSS : 8       |   GND            |   GND
 *      VDD : 16      |   +3.3V          |   +3.3V
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

CD4511 displ = CD4511(A5, A0, A1, A4, A3, A2);

void setup() {
  displ.setup();
}

void loop() {
  //turn on the display
  displ.displayON();

  //display all numbers from 0 to 9 (for 0.5s each)
  for(unsigned char i=0 ; i<10 ; i++){
    displ.display(i);
    displ.commit();
    delay(500);
  }

  //turn off the screen for 1s
  displ.displayOFF();
  delay(1000);
}
