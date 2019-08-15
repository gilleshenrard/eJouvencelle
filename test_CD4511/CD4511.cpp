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
/*  P : Displays the selected number by setting each pin    */
/*      value                                               */
/*  O : /                                                   */
/************************************************************/
void CD4511::display(int Number)
{
  digitalWrite(LED_BUILTIN, HIGH);
  if(Number > -1 && Number < 10){
    
    //set each value pin by cutting each of 4 first bits of Number
    if(Number & 1)
      digitalWrite(this->a, HIGH);
    else
      digitalWrite(this->a, LOW);
    
    if(Number & 2)
      digitalWrite(this->b, HIGH);
    else
      digitalWrite(this->b, LOW);
    
    if(Number & 4)
      digitalWrite(this->c, HIGH);
    else
      digitalWrite(this->c, LOW);
    
    if(Number & 8)
      digitalWrite(this->d, HIGH);
    else
      digitalWrite(this->d, LOW);

    //pulse the latch with a falling edge to set the new BCD value
    digitalWrite(this->latch, LOW);
    delay(500);
    digitalWrite(this->latch, HIGH);

    //set the blank pin as HIGH to allow number display
    displayON();
  }
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
