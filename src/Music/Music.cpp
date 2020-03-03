#include "Music.h"

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 * P : Builds a new Music module                                *
 * O : /                                                        *
 ****************************************************************/
Music::Music(int Pin)
:isFinished(false), lastnote(false), isStarted(false), m_curNote(0), m_nextNote(0), m_octave(0), m_nbtick(0), m_duration(0)
{
  this->pin=Pin;
}

/****************************************************************
 * I : /                                                        *
 * P : Destroys the current Music module                        *
 * O : /                                                        *
 ****************************************************************/
Music::~Music()
{}

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
  if(!this->finished())
    this->isStarted=true;
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
    if(!this->isStarted)
      return 0;

    //check if note duration has been reached
    if(this->m_nbtick > 0)
    {
        this->m_nbtick--;
        return 0;
    }


    //NOTE UPDATE

    //roll the music to the right (nextNote is off by 1 increment)
    this->m_curNote = this->m_nextNote;
    this->m_nextNote = music.indexOf(' ', this->m_curNote);

    //was the previous tick the last note?
    if(this->m_curNote == -1)
    {
        this->isFinished = true;
        return 0;
    }

    //are there any notes left to decode?
    if(this->m_nextNote == -1)
        this->lastnote = true;
    else
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

    //decode the note requested (octave 0 @ A440 by default)
    float frequency;
    switch(*it)
    { 
      case 'C':
      case 'c':
        frequency = 16.35;
        break;
      
      case 'D':
      case 'd':
        frequency = 18.35;
        break;
      
      case 'E':
      case 'e':
        frequency = 20.6;
        break;
      
      case 'F':
      case 'f':
        frequency = 21.83;
        break;
      
      case 'G':
      case 'g':
        frequency = 24.5;
        break;

      case 'A':
      case 'a':
        frequency = 27.5;
        break;
      
      case 'B':
      case 'b':
        frequency = 30.87;
        break;
      
      case 'R':
      case 'r':
      default:
        frequency = 0.0;
        break;
    }

    //shift the note to the right octave (2 pow(octave))
    unsigned char multiplier = 1;
    frequency *= (float)(multiplier << this->m_octave);
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

    //if none specified reused last specified
    //otherwise, update specified
    if(!duration)
      duration = this->m_duration;
    else
      this->m_duration = duration;
    this->m_nbtick = 32 / duration;

    //decode dotted note (duration * 1.5)
    if (note.indexOf(".") != -1)
        this->m_nbtick = (unsigned char)((float)this->m_nbtick * 1.5);

    tone(this->pin, frequency);

    return 0;
}

/****************************************************************
 * I : /                                                        *
 * P : Stops playing                                            *
 * O : /                                                        *
 ****************************************************************/
void Music::stop(){
    noTone(this->pin);
    this->isStarted=false;
}

/****************************************************************
 * I : /                                                        *
 * P : Resets the melody                                        *
 * O : /                                                        *
 ****************************************************************/
void Music::reset(){
  this->lastnote=false;
  this->isFinished=false;
  this->m_curNote = 0;
  this->m_nextNote = 0;
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
