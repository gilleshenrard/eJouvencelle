#include "Music.h"

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 * P : Builds a new Music module                                *
 * O : /                                                        *
 ****************************************************************/
Music::Music(int Pin, int notes[], const int notesSz, int notesLen[], int newBPM)
:noteIndex(0), prevTime(0), finished(false), started(false)
{
  this->pin=Pin;
  this->Notes=notes;
  this->NotesSize=notesSz;
  this->NotesLength=notesLen;
  this->BPM=newBPM;
}

/****************************************************************
 * I : /                                                        *
 * P : Destroys the current Music module                        *
 * O : /                                                        *
 ****************************************************************/
Music::~Music()
{}

/****************************************************************
 * I : BPM to assign                                            *
 * P : Changes the BPM of the melody                            *
 * O : /                                                        *
 ****************************************************************/
void Music::setBPM(int newBPM){
  this->BPM = newBPM;
}

/****************************************************************
 * I : /                                                        *
 * P : Plays the current selected note                          *
 * O : /                                                        *
 ****************************************************************/
void Music::setup(){
  pinMode(this->pin, OUTPUT);
}

/****************************************************************
 * I : /                                                        *
 * P : Plays the current selected note                          *
 * O : /                                                        *
 ****************************************************************/
void Music::start(unsigned long curTime){
  if(!this->finished && !this->started)
  {
    tone(this->pin, this->Notes[this->noteIndex]);
    this->started=true;
    this->prevTime=curTime;
  }
}

/****************************************************************
 * I : /                                                        *
 * P : Stops playing                                            *
 * O : /                                                        *
 ****************************************************************/
void Music::stop(){
  if(this->started)
  {
    noTone(this->pin);
    this->started=false;
  }
}

/****************************************************************
 * I : /                                                        *
 * P : Resets the melody                                        *
 * O : /                                                        *
 ****************************************************************/
void Music::reset(){
  this->noteIndex=0;
  this->last=false;
  this->finished=false;
}

/****************************************************************
 * I : /                                                        *
 * P : Handles the beat for the music, and updates finished     *
 * O : /                                                        *
 ****************************************************************/
void Music::refresh(unsigned long curTime){
  if(this->NotesLength[this->noteIndex] && this->started && !this->finished)
  {
    unsigned long lengthMillis=60000 / (this->BPM * this->NotesLength[this->noteIndex]);
    unsigned long lapse = curTime - this->prevTime;
  
    if(lapse >= lengthMillis)
    {
      this->stop();
      this->noteIndex++;
      if(this->noteIndex+1 >= this->NotesSize)
        this->last=true;

      if(this->noteIndex >= this->NotesSize)
        this->finished=true;

      this->start(curTime);
    }
  }
}

/****************************************************************
 * I : /                                                        *
 * P : Informs about whether the melody is started or not       *
 * O : Melody state                                             *
 ****************************************************************/
bool Music::isStarted()
{
  return this->started;
}

/****************************************************************
 * I : /                                                        *
 * P : Informs about whether the melody is finished or not      *
 * O : Melody state                                             *
 ****************************************************************/
bool Music::isFinished()
{
  return this->finished;
}

/****************************************************************
 * I : /                                                        *
 * P : Informs about whether the melody is finished or not      *
 * O : Melody state                                             *
 ****************************************************************/
bool Music::lastNote()
{
  return this->last;
}
