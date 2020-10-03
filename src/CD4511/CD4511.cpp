#include "CD4511.h"

/************************************************************/
/*  I : Matching pin numbers for each decoder pin           */
/*		Pin number of the Latch Enable decoder pin 			      */
/*		Pin number of the Blank decoder pin (ignored by def.) */
/*		Pin number of the Test decoder pin (ignored by def.)  */
/*    Pin number of the Dot LED (ignored by def.)           */
/*  P : Builds and initialises a new CD4511 decoder	        */
/*      with the matching pin numbers                       */
/*  O : /                                                   */
/************************************************************/
CD4511::CD4511(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char latch, unsigned char blank = -1, unsigned char test = -1, unsigned char dot = -1)
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
  this->dot=t_dot;
}

/************************************************************/
/*  I : /                                                   */
/*  P : Sets the display pins as output                     */
/*  O : /                                                   */
/************************************************************/
void CD4511::setup()
{
	//set the BCD value to 0
	pinMode((int)this->a, OUTPUT);
	digitalWrite((int)this->a, LOW);
 
	pinMode((int)this->b, OUTPUT);
	digitalWrite((int)this->b, LOW);
	
	pinMode((int)this->c, OUTPUT);
	digitalWrite((int)this->c, LOW);
	
	pinMode((int)this->d, OUTPUT);
	digitalWrite((int)this->d, LOW);

	//setup latch pin and send a pulse to fixate the 0 value
	pinMode((int)this->latch, OUTPUT);
	digitalWrite((int)this->latch, LOW);
	digitalWrite((int)this->latch, HIGH);
	
	//enable the blank pin if selected
	if(this->blank > -1)
		pinMode((int)this->blank, OUTPUT);

	//enable the test pin if selected
	if(this->test > -1)
		pinMode((int)this->test, OUTPUT);
}

/************************************************************/
/*  I : Number to display                                   */
/*  P : Sets each pin on the CD4511 to display the number   */
/*        when the blank pin is released                    */
/*  O : /                                                   */
/************************************************************/
/*  WARNING : to actually display a number, the method      */
/*            commit() must be called afterwards            */
/*            (CD4511 needs a falling edge on the latch pin)*/
/************************************************************/
void CD4511::display(int Number)
{
  output_u decoder;

  //set the char part of the union with Number
  decoder.nb = (char)Number;

  //set each value pin by cutting each of 4 first bits of Number
  digitalWrite((int)this->a, decoder.pinsval.a);
  digitalWrite((int)this->b, decoder.pinsval.b);
  digitalWrite((int)this->c, decoder.pinsval.c);
  digitalWrite((int)this->d, decoder.pinsval.d);
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
  if(this->blank > -1)
    digitalWrite((int)this->blank, LOW);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display on                                */
/*  O : /                                                   */
/************************************************************/
void CD4511::displayON()
{
  if(this->blank > -1)
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
