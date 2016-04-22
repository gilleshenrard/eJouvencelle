#include"Music.h"

unsigned long prevTime = 0;
bool started=false;

int notes[5]={440, 550, 660, 770, 880};
int length[5]={2, 4, 4, 2, 2};
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
}
