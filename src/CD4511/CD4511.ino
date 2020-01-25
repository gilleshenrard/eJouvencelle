#include "CD4511.h"

/*
 * Devices used during tests :
 *  - 1 x Arduino Nano V3
 *  - 1 x CD4511
 *  - 7 x 220 Ohms resistors
 *  - 1 x com. cathode 7-segment (FJ11001AH)
 * 
 * CD4511 library testing procedure
 * --------------------------------
 *      CD4511 pins   |   Arduino pins
 *      B : 1         |   D6
 *      C : 2         |   D7
 *      Test : 3      |   +5V
 *      Blank : 4     |   D10
 *      Latch : 5     |   D9
 *      D : 6         |   D8
 *      A : 7         |   D5
 *      VSS : 8       |   GND
 *      VDD : 16      |   +5V
 *      
 *      CD4511 pins   |   7 segment display (pin 1 bottom left)
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

CD4511 displ = CD4511(5, 6, 7, 8, 9, 10);

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
