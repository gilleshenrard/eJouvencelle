#include "CD4511.h"

/************************************************************/
/*  I : Matching pin numbers for each decoder pin (A,B,C,D) */
/*		Pin number of the Latch Enable decoder pin 			      */
/*		Pin number of the Blank decoder pin (ignored by def.) */
/*		Pin number of the Test decoder pin (ignored by def.)  */
/*    Pin number of the Dot LED (ignored by def.)           */
/*  P : Builds and initialises a new CD4511 decoder	        */
/*      with the matching pin numbers                       */
/*  O : /                                                   */
/************************************************************/
CD4511::CD4511(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char latch, unsigned char blank, unsigned char test, unsigned char dot)
{
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
  this->latch = latch;
  this->blank = blank;
  this->test = test;
  this->setDot(dot);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Destroys the current CD4511                     	  */
/*  O : /                                                   */
/************************************************************/
CD4511::~CD4511()
{}

/************************************************************/
/*  I : Pin number to assign to the display dot             */
/*  P : assigns pin numbers to display dot                  */
/*  O : /                                                   */
/************************************************************/
void CD4511::setDot(unsigned char t_dot)
{
  this->dot = t_dot;
}

/************************************************************/
/*  I : /                                                   */
/*  P : Sets the display pins as output                     */
/*  O : /                                                   */
/************************************************************/
void CD4511::setup()
{
	//set mandatory pins as outputs
	pinMode((int)this->a, OUTPUT);
  pinMode((int)this->b, OUTPUT);
  pinMode((int)this->c, OUTPUT);
  pinMode((int)this->d, OUTPUT);
  pinMode((int)this->latch, OUTPUT);

	//enable the blank pin if selected
	if(this->blank != IGNORE_PIN)
		pinMode((int)this->blank, OUTPUT);

	//enable the test pin if selected
	if(this->test != IGNORE_PIN)
		pinMode((int)this->test, OUTPUT);

 //enable the dot pin if selected
  if(this->dot != IGNORE_PIN)
    pinMode((int)this->dot, OUTPUT);
}

/************************************************************/
/*  I : Number to display                                   */
/*  P : Sets each pin on the CD4511 to display the number   */
/*        when the blank pin is released                    */
/*  O : 0 if the number to display is between 0 and 9       */
/*     -1 otherwise                                         */
/************************************************************/
/*  WARNING : to actually display a number, the method      */
/*            commit() must be called afterwards            */
/*            (CD4511 needs a falling edge on the latch pin)*/
/************************************************************/
int CD4511::display(int Number)
{
  if(Number < 0 || Number > 9)
    return -1;
  
  output_u decoder;

  //set the char part of the union with Number
  decoder.nb = (char)Number;

  //set each value pin by cutting each of 4 first bits of Number
  digitalWrite((int)this->a, decoder.pinsval.a);
  digitalWrite((int)this->b, decoder.pinsval.b);
  digitalWrite((int)this->c, decoder.pinsval.c);
  digitalWrite((int)this->d, decoder.pinsval.d);

  return 0;
}

/************************************************************/
/*  I : /                                                   */
/*  P : Sends a falling edge to the latch pin (commits val.)*/
/*  O : /                                                   */
/************************************************************/
void CD4511::commit()
{
    //pulse the latch with a falling edge to set the new BCD value
    digitalWrite((int)this->latch, LOW);
    digitalWrite((int)this->latch, HIGH);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display off                               */
/*  O : /                                                   */
/************************************************************/
void CD4511::displayOFF()
{
  if(this->blank != IGNORE_PIN)
    digitalWrite((int)this->blank, LOW);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display on                                */
/*  O : /                                                   */
/************************************************************/
void CD4511::displayON()
{
  if(this->blank != IGNORE_PIN)
    digitalWrite((int)this->blank, HIGH);
}

/************************************************************/
/*  I : level to set to the dot (true by default)           */
/*  P : Turns the dot on the display on                     */
/*  O : /                                                   */
/************************************************************/
void CD4511::displayDot(bool state)
{
  digitalWrite((int)this->dot, (state ? HIGH : LOW));
}
