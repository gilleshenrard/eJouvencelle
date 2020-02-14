#include "Music.h"

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 * P : Builds a new Music module                                *
 * O : /                                                        *
 ****************************************************************/
Music::Music(int Pin, int notes[], const int notesSz, int notesLen[], int newBPM = 0)
:noteIndex(0), prevTime(0), isFinished(false), lastnote(false), isStarted(false)
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
  if(!this->finished() && !this->started())
  {
    tone(this->pin, this->Notes[this->noteIndex]);
    this->isStarted=true;
    this->prevTime=curTime;
  }
}

/****************************************************************/
/*  I : Music MML string to decode                              */
/*  P : When a tick is reached, decode a note and play it       */
/*  O : NOTEERR : error while decoding                          */
/*      NOTEOK  : note properly decoded                         */
/*      LASTNOTE: no further notes afterwards                   */
/*      ENDNOTE : last note has been played, end of music       */
/****************************************************************/
int Music::onTick(String& music)
{
    //check if note duration has been reached
    if(this->m_nbtick > 0)
    {
        this->m_nbtick--;
        return NOTEOK;
    }

    //NOTE UPDATE

    //was the previous tick the last note?
    if(this->m_nextNote == -1)
        return ENDNOTE;

    //roll the music to the right (nextNote is off by 1 increment)
    this->m_curNote = this->m_nextNote;
    this->m_nextNote = music.indexOf(' ', this->m_curNote);

    //are there any notes left to decode?
    if(this->m_nextNote == -1)
        return LASTNOTE;

    //update nextNote to point to an actual note
    this->m_nextNote ++;


    //NOTE DECODING

    //get the code for the current note
    String note = music.substring(this->m_curNote, this->m_nextNote - 1);
    char* it = note.c_str();

    //decode eventual octave change
    if(isdigit(*it))
    {
        this->m_octave = *it - 48; //translate from ASCII -> shift 48
        it++;
    }

    //decode the note requested (7th octave by default)
    float frequency = 0;
    switch(*it)
    {
        case 'a':
            frequency = 2093.0;
            break;
        case 'b':
            frequency = 2349.0;
            break;
        case 'c':
            frequency = 2637.0;
            break;
        case 'd':
            frequency = 2794.0;
            break;
        case 'e':
            frequency = 3136.0;
            break;
        case 'f':
            frequency = 3520.0;
            break;
        case 'g':
            frequency = 3951.0;
            break;
        case 'r':
            frequency = 0.0;
            break;
    }

    //shift the note to the right octave
    frequency = frequency / (float)Music::divisors[this->m_octave];
    it++;

    //decode sharp or flat notes
    if ((*it == '#') || (*it =='+'))
    {
        frequency *= 1.059;
        it++;
    }
    if (*it == '-')
    {
        frequency /= 1.059;
        it++;
    }

    //decode note duration (nb of ticks = nb of 1/32 notes)
    int index = note.indexOf(*it);
    note = note.substring(index);
    unsigned char duration = (unsigned char)note.toInt();
    this->m_nbtick = 32 / duration;

    //decode dotted note (duration * 1.5)
    if (note.indexOf(".") != -1)
        this->m_nbtick = (unsigned char)((float)this->m_nbtick * 1.5);

    return NOTEOK;
}

/****************************************************************
 * I : /                                                        *
 * P : Stops playing                                            *
 * O : /                                                        *
 ****************************************************************/
void Music::stop(){
  if(this->started())
  {
    noTone(this->pin);
    this->isStarted=false;
  }
}

/****************************************************************
 * I : /                                                        *
 * P : Resets the melody                                        *
 * O : /                                                        *
 ****************************************************************/
void Music::reset(){
  this->noteIndex=0;
  this->lastnote=false;
  this->isFinished=false;
}

/****************************************************************
 * I : /                                                        *
 * P : Handles the beat for the music, and updates finished     *
 * O : /                                                        *
 ****************************************************************/
void Music::refresh(unsigned long curTime){
  if(this->NotesLength[this->noteIndex] && this->started() && !this->finished())
  {
    unsigned long lengthMillis=60000 / (this->BPM * this->NotesLength[this->noteIndex]);
    unsigned long lapse = curTime - this->prevTime;
  
    if(lapse >= lengthMillis)
    {
      this->stop();
      this->noteIndex++;
      if(this->noteIndex+1 >= this->NotesSize)
        this->lastnote=true;

      if(this->noteIndex >= this->NotesSize)
      {
        this->isFinished=true;
        this->lastnote=false;
      }

      this->start(curTime);
    }
  }
}

/****************************************************************
 * I : /                                                        *
 * P : Informs about whether the melody is started or not       *
 * O : Melody state                                             *
 ****************************************************************/
bool Music::started()
{
  return this->isStarted;
}

/****************************************************************
 * I : /                                                        *
 * P : Informs about whether the melody is finished or not      *
 * O : Melody state                                             *
 ****************************************************************/
bool Music::finished()
{
  return this->isFinished;
}

/****************************************************************
 * I : /                                                        *
 * P : Informs about whether the melody is finished or not      *
 * O : Melody state                                             *
 ****************************************************************/
bool Music::last()
{
  return this->lastnote;
}
