#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <Arduino.h>

class Music{
  private:
      int pin;
      int *Notes;
      int *NotesLength;
      int NotesSize;
      int noteIndex;
      int BPM;
      unsigned long prevTime;
      bool isFinished;
      bool lastnote;
      bool isStarted;

  public:
      Music(int Pin, int notes[]=NULL, const int notesSz=0, int notesLen[]=NULL, int newBPM=0);
      ~Music();
      void setBPM(int);
      void setup();
      void start(unsigned long curTime);
      void stop();
      void reset();
      void refresh(unsigned long curTime);

      bool started();
      bool finished();
      bool last();
};
#endif
