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
  if(this->pinSet && Number > -1 && Number < 10)
  {
	  digitalWrite(this->pins[0], segDisplay::numbers[Number].segments.a);
	  digitalWrite(this->pins[1], segDisplay::numbers[Number].segments.b);
	  digitalWrite(this->pins[2], segDisplay::numbers[Number].segments.c);
	  digitalWrite(this->pins[3], segDisplay::numbers[Number].segments.d);
	  digitalWrite(this->pins[4], segDisplay::numbers[Number].segments.e);
	  digitalWrite(this->pins[5], segDisplay::numbers[Number].segments.f);
	  digitalWrite(this->pins[6], segDisplay::numbers[Number].segments.g);
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
void segDisplay::displayDot(bool state)
{
  if(this->pinSet)
  {
    if(state)
      digitalWrite(this->dot, HIGH);
    else
      digitalWrite(this->dot, LOW);
  }
}
