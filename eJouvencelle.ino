#include"src/CD4511/CD4511.h"
#include"src/MMLtone/MMLtone.h"

/* PINOUT
 *  
 * CD4511 library testing procedure
 * --------------------------------
 *      CD4511 pins   |   Arduino pins   |   Atmega328p-au
 *      --------------|------------------|----------------
 *      B   : 1       |   D10            |   14  : PB2
 *      C   : 2       |   D9             |   13  : PB1
 *      LT  : 3       |   +5V            |   +5V
 *      BL  : 4       |   D8             |   12  : PB0
 *      LE  : 5       |   D7             |   11  : PD7
 *      D   : 6       |   D6             |   10  : PD6
 *      A   : 7       |   D5             |   9   : PD5
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
 *                    
 *  Music
 * -------------------------------------------------------
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

//timer1 values with 16 MHz crystal
// 1/64 notes are chosen as smallest musical increment
// (value = 16,000,000 / (prescaler * Hz) - 1) -> must be < 65536 for timer1
#define BPM120CRY 62499 // 32Hz tick (1/64 note at 120 BPM)
#define BPM140CRY 53570 // 37.333Hz tick (1/64 note at 140 BPM)
#define BPM160CRY 46873 // 42.667Hz tick (1/64 note at 160 BPM)

//timer1 values with 8 MHz internal resonator
// 1/64 notes are chosen as smallest musical increment
// (value = 8,000,000 / (prescaler * Hz) - 1) -> must be < 65536 for timer1
#define BPM120INT 31249 // 32Hz tick (1/64 note at 120 BPM)
#define BPM140INT 26784 // 37.333Hz tick (1/64 note at 140 BPM)
#define BPM160INT 23436 // 42.667Hz tick (1/64 note at 160 BPM)

#define startbutton 3
#define resetbutton 2

unsigned long prevTime = 0;
volatile bool started=false, reseted=false, last=false;

MMLtone melody = MMLtone(12, "5d8 e f g f e d c d e f g f e d c d e f g f e4 d8 g f e d c");

CD4511 display = CD4511(5, 10, 9, 6, 7, 8);
bool displayOn=false, numberSet=false;
unsigned char number = 0, flicker=0;

/******************************************************************************/
/*  I : /                                                                     */
/*  P : Initiates all the I/O pins and variables                              */
/*  O : /                                                                     */
/******************************************************************************/
void setup() {
  display.setup();
  display.displayON();
  display.display(number);
  display.commit();
  melody.setup();

  pinMode(startbutton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(startbutton), startbuttonfell, FALLING);
  pinMode(resetbutton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(resetbutton), resetbuttonfell, FALLING);

  //stop interrupts
  cli();

  //clear TCCR1
  TCCR1A = 0;
  TCCR1B = 0;

  //reset counter value +
  //set compare match register for 32 Hz increments
  TCNT1  = 0;
  OCR1A = BPM120CRY;

  // turn on CTC mode
  // + Set CS12, CS11 and CS10 bits for 8 prescaler
  // + enable timer compare interrupt
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);
  TIMSK1 |= (1 << OCIE1A);

  //allow interrupts
  sei();
}

/******************************************************************************/
/*  I : /                                                                     */
/*  P : Program main loop                                                     */
/*  O : /                                                                     */
/******************************************************************************/
void loop() {
  unsigned long newTime = millis();

  if(started)
  {
    melody.start();
    if(melody.last() && !last)
      animate(newTime);
  }
  else
  {
    melody.stop();
    if(reseted)
    {
      melody.reset();
      number=0;
      display.display(number);
      display.commit();
      reseted=false;
      displayOn=false;
      numberSet=false;
      flicker=0;
    }
  }
}

/****************************************************************************/
/*  I : timer1 comparator vector                                            */
/*  P : toggle pin 13 at 32Hz (16Hz full wave)                              */
/*  O : /                                                                   */
/****************************************************************************/
ISR(TIMER1_COMPA_vect){
  if(!melody.started())
    return;
  
  melody.onTick();
}

/**********************************************************************************/
/*  I : /                                                                         */
/*  P : Handles the push on the animation                                         */
/*  O : /                                                                         */
/**********************************************************************************/
void animate(unsigned long newTime)
{
  if(flicker<=20)
  {
    if(newTime-prevTime>=125)
    {
      displayOn = !displayOn;
      prevTime=newTime;
      flicker++;
    }
  
    if(displayOn)
      display.displayON();
    else
      display.displayOFF();
  }
  else
  {
    if(newTime-prevTime>=2000)
    {
      if(!numberSet)
      {
        number++;
        display.displayON();
        display.display(number);
        display.commit();
        numberSet=true;
      }
      else
      {
        melody.reset();
        displayOn=false;
        numberSet=false;
        flicker=0;
        last=false;
      }
      prevTime=newTime;
    }
  }
}

/**********************************************************************************/
/*  I : /                                                                         */
/*  P : Handles the push on the start button                                      */
/*  O : /                                                                         */
/**********************************************************************************/
void startbuttonfell()
{
  started=!started;
}

/**********************************************************************************/
/*  I : /                                                                         */
/*  P : Handles the push on the reset button                                      */
/*  O : /                                                                         */
/**********************************************************************************/
void resetbuttonfell()
{
  reseted=true;
}
