#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <Arduino.h>

class Music{
  private:
      int pin;
      unsigned lon prevTime;
      int *Notes;
      int NotesSize;
      int *NotesLength;
      int NotesLengthSize;
      int noteCount;

  public:
      Music(int);
      Music(int, int[], const int, int[], const int);
      ~Music();
      void setNotes(int[], const int);
      void setNotesLength(int[], const int);
      void setup();
      void start();
      void stop();
      void reset();
      void refresh(unsigned long);
};
#endif
