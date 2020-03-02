#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <Arduino.h>

class Music
{
  static constexpr unsigned char divisors[] = {0,1,2,4,8,16,32,64,128};
  
  private:
      int pin;
      bool isFinished;
      bool lastnote;
      bool isStarted;
      int             m_curNote;
      int             m_nextNote;
      unsigned char   m_octave;
      unsigned char   m_nbtick;
      unsigned char   m_duration;

  public:
      Music(int Pin);
      ~Music();
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
