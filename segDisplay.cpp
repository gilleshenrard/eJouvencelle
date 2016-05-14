#include "segDisplay.h"

constexpr t_display segDisplay::numbers[];

/************************************************************/
/*  I : /                                                   */
/*  P : Builds and initialises a new 7-segment display      */
/*  O : /                                                   */
/************************************************************/
segDisplay::segDisplay()
:pinSet(false), dot(0)
{}

/************************************************************/
/*  I : Matching pin numbers for each segment               */
/*  P : Builds and initialises a new 7-segment display      */
/*      with the matching pin numbers                       */
/*  O : /                                                   */
/************************************************************/
segDisplay::segDisplay(int a, int b, int c, int d, int e, int f, int g)
:pinSet(false), dot(0)
{
  setPins(a, b, c, d, e, f, g);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Destroys the current segDisplay                     */
/*  O : /                                                   */
/************************************************************/
segDisplay::~segDisplay()
{}

/************************************************************/
/*  I : Pin number to assign to each segment                */
/*  P : assigns pin numbers to display segments             */
/*  O : /                                                   */
/************************************************************/
void segDisplay::setPins(int a, int b, int c, int d, int e, int f, int g)
{
  int tmp[7]={a, b, c, d, e, f, g};
  for(char i=0 ; i<7 ; i++)
    this->pins[i]=tmp[i];
    
  this->pinSet=true;
}

/************************************************************/
/*  I : Pin number to assign to the display dot             */
/*  P : assigns pin numbers to display dot                  */
/*  O : /                                                   */
/************************************************************/
void segDisplay::setDot(int t_dot)
{
  this->dot=t_dot;
}

/************************************************************/
/*  I : /                                                   */
/*  P : Sets the display pins as output                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::setup()
{
  if(this->pinSet)
  {
    for(char i=0 ; i<7 ; i++)
      pinMode(this->pins[i], OUTPUT);
  }
}

/************************************************************/
/*  I : Number to display                                   */
/*  P : Displays the selected number by setting each pin    */
/*      value                                               */
/*  O : /                                                   */
/************************************************************/
void segDisplay::display(int Number)
{
  if(this->pinSet)
  {
    /*Each bit of the byte numbers[number] corresponds to the value to assign to a led of the display
      Starting with i at the 7th bit in numbers[number]
      Starting with j at the pin corresponding to the segment A
      At each loop :
        - Testing value of the current bit into numbers[number] with a '&' operation
        - If result != 0 : writing HIGH into the current pin
        - If result == 0 : writing LOW
        - Stepping to the next bit and the next pin*/
  
    for(char i=64, j=0 ; i>0 ; i/=2, j++)
    {
      if(segDisplay::numbers[Number].display & i)
        digitalWrite(this->pins[j], HIGH);    //if test value != 0 -> true then HIGH
      else
        digitalWrite(this->pins[j], LOW);     //else, the bit is set to 0, thus the signal is LOW
    }
  }
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display off                               */
/*  O : /                                                   */
/************************************************************/
void segDisplay::noDisplay()
{
  if(this->pinSet)
  {
    for(char i=0 ; i<7 ; i++)
      digitalWrite(this->pins[i], LOW);
  }
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the dot on the display on                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::displayDot(bool state=true)
{
  if(this->pinSet)
  {
    if(state)
      digitalWrite(this->dot, HIGH);
    else
      digitalWrite(this->dot, LOW);
  }
}
