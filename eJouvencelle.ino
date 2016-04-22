#include"segDisplay.h"
#include"Music.h"

int startbutton=3;
int resetbutton=2;

unsigned long prevTime = 0;
bool started=false;

int notes[5]={440, 550, 660, 770, 880};
int length[5]={2, 4, 4, 2, 2};
Music melody = Music(12, notes, 5, length, 60);

segDisplay display = segDisplay(7, 8, 11, 10, 9, 6, 5);
int number = 0;

void setup() {
  display.setup();
  display.display(number);
  melody.setup();

  pinMode(startbutton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(startbutton), startbuttonfell, FALLING);
  pinMode(resetbutton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(resetbutton), resetbuttonfell, FALLING);
}

void loop() {
  unsigned long newTime = millis();
  
  if(newTime-prevTime >= 1000 && started)
  {
    number++;
    number%=10;
    display.display(number);
    prevTime = newTime;
  }

  melody.refresh(newTime);
}

void startbuttonfell()
{
  started=!started;
  if(started)
    melody.start();
  else
    melody.stop();
}

void resetbuttonfell()
{
  melody.reset();
  display.display(0);
}
