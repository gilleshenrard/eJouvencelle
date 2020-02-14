#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <Arduino.h>

#define NOTEERR -1
#define NOTEOK 0
#define LASTNOTE 1
#define ENDNOTE 2

class Music{

  static constexpr unsigned char divisors[] = {128,64,32,16,8,4,2,1};
  
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
      int             m_curNote;
      int             m_nextNote;
      unsigned char   m_octave;
      unsigned char   m_nbtick;
      unsigned char   m_duration;

  public:
      Music(int Pin, int notes[]=NULL, const int notesSz=0, int notesLen[]=NULL, int newBPM=0);
      ~Music();
      void setBPM(int);
      void setup();
      void start(unsigned long curTime);
      int onTick(String& music);
      void stop();
      void reset();
      void refresh(unsigned long curTime);

      bool started();
      bool finished();
      bool last();
};
#endif
