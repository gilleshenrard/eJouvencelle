#include "segDisplay.h"

constexpr t_display segDisplay::numbers[];

/************************************************************/
/*  I : Matching pin numbers for each segment               */
/*  P : Builds and initialises a new 7-segment display      */
/*      with the matching pin numbers                       */
/*  O : /                                                   */
/************************************************************/
segDisplay::segDisplay(int a, int b, int c, int d, int e, int f, int g)
:dot(0)
{
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
  this->e = e;
  this->f = f;
  this->g = g;
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
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
  this->e = e;
  this->f = f;
  this->g = g;
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
/*  P : Sets the display pins as output and set them LOW    */
/*  O : /                                                   */
/************************************************************/
void segDisplay::setup()
{
  pinMode(this->a, OUTPUT);
  digitalWrite(this->a, LOW);
  
  pinMode(this->b, OUTPUT);
  digitalWrite(this->b, LOW);
  
  pinMode(this->c, OUTPUT);
  digitalWrite(this->c, LOW);
  
  pinMode(this->d, OUTPUT);
  digitalWrite(this->d, LOW);
  
  pinMode(this->e, OUTPUT);
  digitalWrite(this->e, LOW);
  
  pinMode(this->f, OUTPUT);
  digitalWrite(this->f, LOW);
  
  pinMode(this->g, OUTPUT);
  digitalWrite(this->g, LOW);
}

/************************************************************/
/*  I : Number to display                                   */
/*  P : Displays the selected number by setting each pin    */
/*      value                                               */
/*  O : /                                                   */
/************************************************************/
void segDisplay::display(int Number)
{
  if(Number > -1 && Number < 10)
  {
	  digitalWrite(this->a, segDisplay::numbers[Number].segments.a);
	  digitalWrite(this->b, segDisplay::numbers[Number].segments.b);
	  digitalWrite(this->c, segDisplay::numbers[Number].segments.c);
	  digitalWrite(this->d, segDisplay::numbers[Number].segments.d);
	  digitalWrite(this->e, segDisplay::numbers[Number].segments.e);
	  digitalWrite(this->f, segDisplay::numbers[Number].segments.f);
	  digitalWrite(this->g, segDisplay::numbers[Number].segments.g);
  }
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display off                               */
/*  O : /                                                   */
/************************************************************/
void segDisplay::displayOFF()
{
  digitalWrite(this->a, LOW);
  digitalWrite(this->b, LOW);
  digitalWrite(this->c, LOW);
  digitalWrite(this->d, LOW);
  digitalWrite(this->e, LOW);
  digitalWrite(this->f, LOW);
  digitalWrite(this->g, LOW);
}

/************************************************************/
/*  I : level to set to the dot (true by default)           */
/*  P : Turns the dot on the display on                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::displayDot(bool state)
{
  digitalWrite(this->dot, (state ? HIGH : LOW));
}
