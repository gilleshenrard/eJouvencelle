#include "Music.h"

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 * P : Builds a new Music module                                *
 * O : /                                                        *
 ****************************************************************/
Music::Music(int Pin, int notes[], const int notesSz, int notesLen[], int newBPM)
:noteIndex(0), finished(false)
{
  this->prevTime=millis();
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
 * I : Notes array                                              *
 *     Notes array size                                         *
 * P : Destroys the current Music module                        *
 * O : /                                                        *
 ****************************************************************/
void Music::setNotes(int notes[], const int notesS){
  this->Notes = notes;
  this->NotesSize = notesS;
}

/****************************************************************
 * I : Notes array                                              *
 *     Notes array size                                         *
 * P : Destroys the current Music module                        *
 * O : /                                                        *
 ****************************************************************/
void Music::setNotesLength(int notesl[]){
  this->NotesLength = notesl;
}

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
void Music::start(){
  if(!this->isFinished())
    tone(this->pin, this->Notes[this->noteIndex]);
}

/****************************************************************
 * I : /                                                        *
 * P : Stops playing                                            *
 * O : /                                                        *
 ****************************************************************/
void Music::stop(){
  noTone(this->pin);
}

/****************************************************************
 * I : /                                                        *
 * P : Resets the melody                                        *
 * O : /                                                        *
 ****************************************************************/
void Music::reset(){
  this->noteIndex=0;
  this->finished=false;
}

/****************************************************************
 * I : /                                                        *
 * P : Handles the beat for the music, and updates finished     *
 * O : /                                                        *
 ****************************************************************/
void Music::refresh(unsigned long curTime){
  if(this->NotesLength[this->noteIndex])
  {
    unsigned long lengthMillis=60000 / (this->BPM * this->NotesLength[this->noteIndex]);
    unsigned long lapse = curTime - this->prevTime;
  
    if(lapse >= lengthMillis)
    {
      this->stop();
      this->noteIndex++;
      if(this->noteIndex < this->NotesSize)
        this->start();
      else
        this->finished=true;
      this->prevTime=curTime;
    }
  }
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
