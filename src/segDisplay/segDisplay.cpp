#include "segDisplay.h"

constexpr t_display segDisplay::numbers[];

/************************************************************/
/*  I : Matching pin numbers for each segment               */
/*  P : Builds and initialises a new 7-segment display      */
/*      with the matching pin numbers                       */
/*  O : /                                                   */
/************************************************************/
segDisplay::segDisplay(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned char g)
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
void segDisplay::setPins(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned char g)
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
void segDisplay::setDot(unsigned char t_dot)
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
  pinMode((int)this->a, OUTPUT);
  digitalWrite((int)this->a, LOW);
  
  pinMode((int)this->b, OUTPUT);
  digitalWrite((int)this->b, LOW);
  
  pinMode((int)this->c, OUTPUT);
  digitalWrite((int)this->c, LOW);
  
  pinMode((int)this->d, OUTPUT);
  digitalWrite((int)this->d, LOW);
  
  pinMode((int)this->e, OUTPUT);
  digitalWrite((int)this->e, LOW);
  
  pinMode((int)this->f, OUTPUT);
  digitalWrite((int)this->f, LOW);
  
  pinMode((int)this->g, OUTPUT);
  digitalWrite((int)this->g, LOW);
}

/************************************************************/
/*  I : Number to display                                   */
/*  P : Displays the selected number by setting each pin    */
/*      value                                               */
/*  O : /                                                   */
/************************************************************/
void segDisplay::display(unsigned char Number)
{
  digitalWrite(this->a, segDisplay::numbers[Number].segments.a);
  digitalWrite(this->b, segDisplay::numbers[Number].segments.b);
  digitalWrite(this->c, segDisplay::numbers[Number].segments.c);
  digitalWrite(this->d, segDisplay::numbers[Number].segments.d);
  digitalWrite(this->e, segDisplay::numbers[Number].segments.e);
  digitalWrite(this->f, segDisplay::numbers[Number].segments.f);
  digitalWrite(this->g, segDisplay::numbers[Number].segments.g);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display off                               */
/*  O : /                                                   */
/************************************************************/
void segDisplay::displayOFF()
{
  digitalWrite((int)this->a, LOW);
  digitalWrite((int)this->b, LOW);
  digitalWrite((int)this->c, LOW);
  digitalWrite((int)this->d, LOW);
  digitalWrite((int)this->e, LOW);
  digitalWrite((int)this->f, LOW);
  digitalWrite((int)this->g, LOW);
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
