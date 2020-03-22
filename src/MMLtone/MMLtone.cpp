#include "MMLtone.h"

/****************************************************************
 * I : Pin on which the buzzer is plugged                       *
 *     MML music code to play                                   *
 * P : Builds a new MMLtone module                              *
 * O : /                                                        *
 ****************************************************************/
MMLtone::MMLtone(unsigned char Pin, const char* music)
:isFinished(false), lastnote(false), isStarted(false), m_curNote(NULL), m_nextNote(NULL), m_octave(0), m_nbtick(0), m_duration(0)
{
  this->pin = Pin;
  this->m_music = music;
}

/****************************************************************
 * I : /                                                        *
 * P : Destroys the current MMLtone module                      *
 * O : /                                                        *
 ****************************************************************/
MMLtone::~MMLtone()
{}

/****************************************************************
 * I : /                                                        *
 * P : Set the pin as an output                                 *
 * O : /                                                        *
 ****************************************************************/
void MMLtone::setup(){
  pinMode((int)this->pin, OUTPUT);
}

/****************************************************************
 * I : /                                                        *
 * P : Set the isStarted flag as true                           *
 * O : /                                                        *
 ****************************************************************/
void MMLtone::start(){
  if(!this->finished())
    this->isStarted=true;
}

/****************************************************************/
/*  I : /                                                       */
/*  P : When a tick is reached, decode a note and play it       */
/*  O : /                                                       */
/****************************************************************/
int MMLtone::onTick()
{ 
    //if music is supposed to be stopped, exit
    if(!this->isStarted)
      return 0;

    //check if note is still to be played
    if(this->m_nbtick > 0)
    {
        this->m_nbtick--;
        return 0;
    }


    //NOTE POINTERS UPDATE

    //update pointers to get the new current and next notes
    if(!this->m_curNote)
    {
      this->m_curNote = this->m_music;
      this->m_nextNote = this->m_curNote + 1;
    }
    else
      this->m_curNote = this->m_nextNote;

    while(*this->m_nextNote!=' ' && *this->m_nextNote!='\0')
        this->m_nextNote++;

    //rectify the next note pointer (currently points to ' ')
    if(*this->m_nextNote!='\0')
      this->m_nextNote++;

    //if current note end of the MML string, music is finished
    if(*this->m_curNote == '\0')
    {
        this->isFinished = true;
        return 0;
    }

    //check if current note the last one of the string
    if(*this->m_nextNote == '\0')
        this->lastnote = true;


    //NOTE DECODING

    //get the code for the current note + declare all variables
    char* it = this->m_curNote;
    float frequency;
    unsigned char duration = 0;

    //decode eventual octave change
    if(isdigit(*it))
    {
        this->m_octave = *it - 48; //translate ASCII to number ('0' = 48)
        it++;
    }

    //set the base freq. for the note requested (octave 0 @ A440 by default)
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

    //multiply the freq. to get the right octave (freq * 2 ^ octave)
    frequency *= (float)(1 << this->m_octave);
    it++;

    //decode sharp or flat notes
    if ((*it == '#') || (*it =='+'))
    {
        frequency *= 1.059;
        it++;
    }
    if (*it == '-')
    {
        frequency *= 0.9443; // = div 1.059
        it++;
    }

    //play the note
    tone(this->pin, frequency);

    //decode note duration (possible 2 digits)
    if(isdigit(*it))
    {
      duration = *it - 48;
      it++;
    }
    if(isdigit(*it))
    {
      duration = (duration * 10) + (*it - 48);
      it++;
    }

    //if none specified, reuse last specified
    //otherwise, update duration
    if(!duration)
      duration = this->m_duration;
    else
      this->m_duration = duration;

    //set the number of ticks
    // (nb of ticks = nb of 1/64 notes to reach proper duration)
    this->m_nbtick = 64 / duration;

    //decode dotted note (duration * 1.5)
    if (*it == '.')
        this->m_nbtick = (unsigned char)((float)this->m_nbtick * 1.5);

    //decrement tick count (1 cycle is used to refresh note)
    this->m_nbtick--;

    return 0;
}

/****************************************************************
 * I : /                                                        *
 * P : Turn the tone off and unset the started flag             *
 * O : /                                                        *
 ****************************************************************/
void MMLtone::stop(){
    noTone(this->pin);
    this->isStarted=false;
}

/****************************************************************
 * I : /                                                        *
 * P : Reset all the flags to 0                                 *
 * O : /                                                        *
 ****************************************************************/
void MMLtone::reset(){
  this->lastnote=false;
  this->isFinished=false;
  this->m_curNote = NULL;
  this->m_nextNote = NULL;
}

/****************************************************************
 * I : /                                                        *
 * P : Inform about whether the melody is started or not        *
 * O : Melody state                                             *
 ****************************************************************/
bool MMLtone::started()
{
  return this->isStarted;
}

/****************************************************************
 * I : /                                                        *
 * P : Inform about whether the melody is finished or not       *
 * O : Melody state                                             *
 ****************************************************************/
bool MMLtone::finished()
{
  return this->isFinished;
}

/****************************************************************
 * I : /                                                        *
 * P : Informs about whether the last tone is reached or not    *
 * O : Melody state                                             *
 ****************************************************************/
bool MMLtone::last()
{
  return this->lastnote;
}
