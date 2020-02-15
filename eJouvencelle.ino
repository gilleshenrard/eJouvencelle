#include"src/segDisplay/segDisplay.h"
#include"src/Music/Music.h"

/* PINOUT
 *  
 * display
 * -------------------------------------------------------
 *      Arduino pins  |   Atmega328p-au   |   7 segment display (1 bottom left)
 *      --------------|-------------------|------------------------------------
 *      D6            |   9 :PD5          |   e:1
 *      D8            |   10:PD6          |   d:2
 *      D10           |   11:PD7          |   c:4
 *      D11           |   12:PB0          |   b:6
 *      D9            |   13:PB1          |   a:7
 *      D7            |   14:PB2          |   f:9
 *      D5            |   15:PB3          |   g:10
 *                                        |   3 : GND
 *                                        |   8 : GND
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

#define BPM120 62499 // 32Hz tick (1/64 note at 120 BPM)
#define BPM140 53570 // 37.333Hz tick (1/64 note at 140 BPM)
#define BPM160 46873 // 42.667Hz tick (1/64 note at 160 BPM)

#define startbutton 3
#define resetbutton 2

unsigned long prevTime = 0;
volatile bool started=false, reseted=false, last=false, tick=false;

String mel = "5d4 e f g f e d c d e f g f e d c d e f g f e2 d4 g f e d c";
Music melody = Music(12);

segDisplay display = segDisplay(9, 11, 10, 8, 6, 7, 5);
bool displayOn=false, numberSet=false;
unsigned char number = 0, flicker=0;

/******************************************************************************/
/*  I : /                                                                     */
/*  P : Initiates all the I/O pins and variables                              */
/*  O : /                                                                     */
/******************************************************************************/
void setup() {
  display.setup();
  display.display(number);
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
  OCR1A = BPM120;

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

  if(melody.started() && tick)
  {
    tick = false;
    melody.onTick(mel);
  }

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
  tick = true;
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
      display.display(number);
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
        display.display(number);
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
