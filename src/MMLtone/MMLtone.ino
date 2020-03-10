#include "MMLtone.h"

/*
 * Devices used during tests :
 *  - 1 x Arduino Nano V3 / Atmega 328p-au
 *  - 1 x buzzer (part number unknown)
 *  - 1 x 2.2k Ohms resistor (current limitation)
 *  - 1 x 10k Ohms resistor (pull-down)
 *  - 1 x N-channel MOSFET (P3NK507)
 * 
 * Music library testing procedure
 * --------------------------------
 *      MOSFET pins   |   
 *      --------------|------------------
 *      Drain : 1     |   Arduino : D12, Atmega : 16 (+ pull-down to GND in //)
 *      Gate  : 2     |   buzzer -
 *      Source: 3     |   GND
 *      
 *      Buzzer pins   |
 *      --------------|------------------------------------
 *      -             |   MOSFET : 2
 *      +             |   VCC (via 2.2k resistor in series)
 */

//timer1 values
// (value = 16,000,000 / (prescaler * Hz) - 1) -> must be < 65536 for timer1
// 1/64 notes are chosen because smallest musical increment
#define BPM120 62499 // 32Hz tick (1/64 note at 120 BPM)
#define BPM140 53570 // 37.333Hz tick (1/64 note at 140 BPM)
#define BPM160 46873 // 42.667Hz tick (1/64 note at 160 BPM)

volatile bool tick = false;
MMLtone melody = MMLtone(12, "5d4 e f g f e d c d e f g f e d c d e f g f e2 d4 g f e d c");


/****************************************************************************/
/*  I : /                                                                   */
/*  P : Setup procedure                                                     */
/*  O : /                                                                   */
/****************************************************************************/
void setup() {
  //stop interrupts
  cli();
  
  //setup melody and pin 13 (test led)
  melody.setup();
  
  //clear TCCR1
  TCCR1A = 0;
  TCCR1B = 0;

  //reset counter value +
  //set compare match register for 32 Hz increments
  TCNT1  = 0;
  OCR1A = BPM120;

  // turn on CTC mode
  // + Set CS12, CS11 and CS10 bits for 8 prescaler
  // + enable timer compare interrupt
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);
  TIMSK1 |= (1 << OCIE1A);

  //allow interrupts
  sei();

  Serial.begin(9600);
}

/****************************************************************************/
/*  I : timer1 comparator vector                                            */
/*  P : updates the melody at each tick (1/64 note)                         */
/*  O : /                                                                   */
/****************************************************************************/
ISR(TIMER1_COMPA_vect){
  //onTick() takes 215us at worst to finish
  //  -> ok to be put in interrupt function
  melody.onTick();
}

/****************************************************************************/
/*  I : /                                                                   */
/*  P : Main loop                                                           */
/*  O : /                                                                   */
/****************************************************************************/
void loop() {
    if(melody.finished())
      melody.stop();
    else
      melody.start();
}
