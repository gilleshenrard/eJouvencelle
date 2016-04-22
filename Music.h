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
      bool finished;
      bool started;

  public:
      Music(int Pin, int notes[]=NULL, const int notesSz=0, int notesLen[]=NULL, int newBPM=0);
      ~Music();
      void setNotes(int[], const int);
      void setNotesLength(int[]);
      void setBPM(int);
      void setup();
      void start();
      void stop();
      void reset();
      void refresh(unsigned long);

      bool isFinished();
};
#endif
