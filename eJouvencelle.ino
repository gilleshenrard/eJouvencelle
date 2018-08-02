#include"segDisplay.h"
#include"Music.h"
#include"notes.h"

#define startbutton 3
#define resetbutton 2
#define potentiometer A7

unsigned long prevTime = 0;
volatile bool started=false, reseted=false, last=false;

int notes[28]={NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
               NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
               NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5 /*suspension*/, NOTE_D5,
               NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5};
int length[28]={2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2};
int BeatsPM = 100;
Music melody = Music(11, notes, 28, length, BeatsPM);

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
    BeatsPM = map(analogRead(potentiometer), 0, 1023, 80, 140);
    melody.setBPM(BeatsPM);

    melody.start(newTime);
    if(melody.last() && !last)
      last=true;
    if(last)
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

  melody.refresh(newTime);
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
