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

  public:
      Music(int);
      Music(int, int[], const int, int[], int);
      ~Music();
      void setNotes(int[], const int);
      void setNotesLength(int[];
      void setBPM(int);
      void setup();
      void start();
      void stop();
      void reset();
      void refresh(unsigned long);
};
#endif
