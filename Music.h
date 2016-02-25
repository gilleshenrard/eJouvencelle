#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <Arduino.h>

class Music{
  private:
      int pin;
      int *Notes;
      int notesSize;
      int noteCount;

  public:
      Music(int);
      Music(int, int[], const int);
      ~Music();
      void setNotes(int[], const int);
      void Start();
      void Stop();
      void Reset();
      void refresh(unsigned long);
};
#endif
