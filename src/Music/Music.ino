#import "Music.h"
#import "notes.h"

int notes[28]={NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
               NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
               NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5 /*suspension*/, NOTE_D5,
               NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5};
int length[28]={2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2};

int BeatsPM = 100;
Music melody = Music(11, notes, 28, length, BeatsPM);

void setup() {
  melody.setup();

}

void loop() {
  unsigned long newTime = millis();

  melody.start(newTime);
  melody.refresh(newTime);
}
