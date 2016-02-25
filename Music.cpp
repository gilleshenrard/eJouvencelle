#include "Music.h"

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 * P : Builds a new Music module                                *
 * O : /                                                        *
 ****************************************************************/
Music::Music(int Pin)
:pin(Pin), Notes(NULL), notesSize(0), NotesLength(NULL), notesLengthSize(0), noteCount(0)
{}

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 * P : Builds a new Music module                                *
 * O : /                                                        *
 ****************************************************************/
Music::Music(int Pin, int notes[], const int notesSz, int notesLen[], const int notesLenSz)
:pin(Pin), Notes(notes), notesSize(notesSz), NotesLength(NULL), notesLengthSize(notesLen), noteCount(notesLenSz)
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
void Music::setNotes(int notes[], const int notesS){
  Notes = notes;
  notesSize = notesS;
}

/****************************************************************
 * I : Notes array                                              *
 *     Notes array size                                         *
 * P : Destroys the current Music module                        *
 * O : /                                                        *
 ****************************************************************/
void Music::setNotesLength(int notesl[], const int notesLSize){
  NotesLength = notesl;
  notesLengthSize = notesLSize;
}

/****************************************************************
 * I : /                                                        *
 * P : Plays the current selected note                          *
 * O : /                                                        *
 ****************************************************************/
void Music::setup(){
  pinMode(pin, OUTPUT);
}

/****************************************************************
 * I : /                                                        *
 * P : Plays the current selected note                          *
 * O : /                                                        *
 ****************************************************************/
void Music::start(){
  tone(pin, Notes[noteCount]);
}

/****************************************************************
 * I : /                                                        *
 * P : Stops playing                                            *
 * O : /                                                        *
 ****************************************************************/
void Music::stop(){
  noTone(pin);
}

/****************************************************************
 * I : /                                                        *
 * P : Resets the melody                                        *
 * O : /                                                        *
 ****************************************************************/
void Music::reset(){
  noteCount=0;
  finished=false;
}

/****************************************************************
 * I : /                                                        *
 * P : Handles the beat for the music, and updates finished     *
 * O : /                                                        *
 ****************************************************************/
void Music::refresh(unsigned long curTime){
  
}
