#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <Arduino.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define NOTEERR -1
#define NOTEOK 0
#define LASTNOTE 1
#define ENDNOTE 2

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
      size_t          m_curNote;
      size_t          m_nextNote;
      unsigned char   m_octave;
      unsigned char   m_nbtick;

  public:
      Music(int Pin, int notes[]=NULL, const int notesSz=0, int notesLen[]=NULL, int newBPM=0);
      ~Music();
      void setBPM(int);
      void setup();
      void start(unsigned long curTime);
      int onTick(std::string& music);
      void stop();
      void reset();
      void refresh(unsigned long curTime);

      bool started();
      bool finished();
      bool last();
};
#endif
