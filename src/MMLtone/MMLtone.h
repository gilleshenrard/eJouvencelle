#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <Arduino.h>

class MMLtone
{ 
  private:
      int pin;
      bool            isFinished;
      bool            lastnote;
      bool            isStarted;
      char*           m_curNote;
      char*           m_nextNote;
      char*           m_music;
      unsigned char   m_octave;
      unsigned char   m_nbtick;
      unsigned char   m_duration;

  public:
      MMLtone(int Pin, const char* music);
      ~MMLtone();
      void setup();
      void start();
      int onTick();
      void stop();
      void reset();

      bool started();
      bool finished();
      bool last();
};
#endif
