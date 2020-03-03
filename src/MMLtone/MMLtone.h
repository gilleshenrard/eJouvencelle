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
      int             m_curNote;
      int             m_nextNote;
      unsigned char   m_octave;
      unsigned char   m_nbtick;
      unsigned char   m_duration;

  public:
      MMLtone(int Pin);
      ~MMLtone();
      void setup();
      void start();
      int onTick(String& music);
      void stop();
      void reset();

      bool started();
      bool finished();
      bool last();
};
#endif
