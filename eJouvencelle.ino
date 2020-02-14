#include"src/segDisplay/segDisplay.h"
#include"src/Music/Music.h"

#define BPM120 62499 // 32Hz tick (1/64 note at 120 BPM)
#define BPM140 53570 // 37.333Hz tick (1/64 note at 140 BPM)
#define BPM160 46873 // 42.667Hz tick (1/64 note at 160 BPM)

#define startbutton 3
#define resetbutton 2
#define potentiometer A7

unsigned long prevTime = 0;
volatile bool started=false, reseted=false, last=false, tick=false;

String mel = "5d4 e f g f e d c d e f g f e d c d e f g f e2 d4 g f e d c";
Music melody = Music(11);

segDisplay display = segDisplay(8, 9, 10, 4, 5, 6, 7);
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
      display.noDisplay();
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
