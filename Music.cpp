#include "Music.h"

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 * P : Builds a new Music module                                *
 * O : /                                                        *
 ****************************************************************/
Music::Music(int Pin)
:pin(Pin), Notes(NULL), noteCount(0), notesSize(0), finished(false)
{}

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 * P : Builds a new Music module                                *
 * O : /                                                        *
 ****************************************************************/
Music::Music(int Pin, int notes[], const int notesSz)
:pin(Pin), Notes(notes), noteCount(0), notesSize(notesSz), finished(false)
{}

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
void Music::setNotes(int notes[], const int notesSize){
  this->Notes = notes;
  this->notesSize = notesSize;
}

/****************************************************************
 * I : /                                                        *
 * P : Plays the current selected note                          *
 * O : /                                                        *
 ****************************************************************/
void Music::Start(){
  tone(this->pin, this->Notes[this->noteCount]);
}

/****************************************************************
 * I : /                                                        *
 * P : Stops playing                                            *
 * O : /                                                        *
 ****************************************************************/
void Music::Stop(){
  noTone(this->pin);
}

/****************************************************************
 * I : /                                                        *
 * P : Resets the melody                                        *
 * O : /                                                        *
 ****************************************************************/
void Music::Reset(){
  this->noteCount=0;
  this->finished=false;
}

/****************************************************************
 * I : /                                                        *
 * P : Handles the beat for the music, and updates finished     *
 * O : /                                                        *
 ****************************************************************/
void Music::onBeat(){
  this->Stop();

  if(this->noteCount >= this->notesSize){
    this->finished=true;
    this->noteCount=0;
  }
  else
    this->finished = false;

  this->Start();

  this->noteCount+=1;
}

/****************************************************************
 * I : /                                                        *
 * P : Tells if the melody is finished                          *
 * O : /                                                        *
 ****************************************************************/
bool Music::isFinished(){
  return this->finished;
}
