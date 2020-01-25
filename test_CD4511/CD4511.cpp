#include "CD4511.h"

/************************************************************/
/*  I : Matching pin numbers for each decoder pin           */
/*		Pin number of the Latch Enable decoder pin 			*/
/*		Pin number of the Blank decoder pin 				*/
/*		Pin number of the Test decoder pin 					*/
/*  P : Builds and initialises a new CD4511 decoder	        */
/*      with the matching pin numbers                       */
/*  O : /                                                   */
/************************************************************/
CD4511::CD4511(int a, int b, int c, int d, int latch, int blank, int test)
{
  this->a = a;
  this->b = b;
  this->c = c;
  this->d = d;
  this->latch = latch;
  this->blank = blank;
  this->test = test;
}

/************************************************************/
/*  I : /                                                   */
/*  P : Destroys the current CD4511                     	*/
/*  O : /                                                   */
/************************************************************/
CD4511::~CD4511()
{}

/************************************************************/
/*  I : /                                                   */
/*  P : Sets the display pins as output                     */
/*  O : /                                                   */
/************************************************************/
void CD4511::setup()
{
	//set the BCD value to 0
	pinMode(this->a, OUTPUT);
	digitalWrite(this->a, LOW);
	pinMode(this->b, OUTPUT);
	digitalWrite(this->b, LOW);
	pinMode(this->c, OUTPUT);
	digitalWrite(this->c, LOW);
	pinMode(this->d, OUTPUT);
	digitalWrite(this->d, LOW);

	//setup latch pin and send a pulse to fixate the 0 value
	pinMode(this->latch, OUTPUT);
	digitalWrite(this->latch, LOW);
	digitalWrite(this->latch, HIGH);
	
	//enable the blank pin if selected
	if(this->blank > -1)
		pinMode(this->blank, OUTPUT);

	//enable the test pin if selected
	if(this->test > -1)
		pinMode(this->test, OUTPUT);
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
void CD4511::setNumber(int Number)
{
  output_u decoder;
  
  if(Number > -1 && Number < 10){
    decoder.nb = (char)Number;

    //set each value pin by cutting each of 4 first bits of Number
    digitalWrite(this->a, (decoder.pinsval.a ? HIGH : LOW));
    digitalWrite(this->b, (decoder.pinsval.b ? HIGH : LOW));
    digitalWrite(this->c, (decoder.pinsval.c ? HIGH : LOW));
    digitalWrite(this->d, (decoder.pinsval.d ? HIGH : LOW));
  }
}

/************************************************************/
/*  I : /                                                   */
/*  P : Sends a falling edge to the latch pin (commits val.)*/
/*  O : /                                                   */
/************************************************************/
void CD4511::commit()
{
    //pulse the latch with a falling edge to set the new BCD value
    digitalWrite(this->latch, LOW);
    digitalWrite(this->latch, HIGH);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display off                               */
/*  O : /                                                   */
/************************************************************/
void CD4511::displayOFF()
{
  if(this->blank > -1)
    digitalWrite(this->blank, LOW);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display on                                */
/*  O : /                                                   */
/************************************************************/
void CD4511::displayON()
{
  if(this->blank > -1)
    digitalWrite(this->blank, HIGH);
}
