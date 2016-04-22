<<<<<<< HEAD
#include"Music.h"

unsigned long prevTime = 0;
bool started=false;

int notes[5]={440, 550, 660, 770, 880};
int length[5]={2, 4, 4, 2, 0};
Music melody = Music(3, notes, 5, length, 60);

void setup() {
  melody.setup();
}

void loop() {
  if(!started)
  {
    melody.start();
    started=true;
  }
  
  prevTime = millis();
  melody.refresh(prevTime);
=======
#include"segDisplay.h"

segDisplay display = segDisplay(2, 3, 5, 6, 7, 8, 10);
unsigned long prevTime = millis();
int number = 0, dot=LOW;

void setup() {
  display.setup();
  display.display(number);
  display.setDot(11);
}

void loop() {
  unsigned long newTime = millis();
  if(newTime-prevTime >= 1000)
  {
    dot = !dot;
    display.displayDot(dot);
    number++;
    number%=10;
    display.display(number);
    prevTime = newTime;
  }
>>>>>>> refs/remotes/origin/master
}
