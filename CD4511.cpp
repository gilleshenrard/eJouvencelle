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
  this.a = a;
  this.b = b;
  this.c = c;
  this.d = d;
  this.latch = latch;
  this.blank = blank;
  this.test = test;
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

	//set the latch to HIGH to avoid further modification
	pinMode(this->latch, OUTPUT);
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
  if(Number > -1 && Number < 10){
    //set the blank pin as HIGH to allow number display
    if(this->blank > -1)
      digitalWrite(this->blank, HIGH);

    //set each value pin by cutting each of 4 first bits of Number
    digitalWrite(this->a, (Number & 1 == 0 ? LOW : HIGH));
    digitalWrite(this->b, (Number & 2 == 0 ? LOW : HIGH));
    digitalWrite(this->c, (Number & 4 == 0 ? LOW : HIGH));
    digitalWrite(this->d, (Number & 8 == 0 ? LOW : HIGH));

    //pulse the latch with a falling edge to set the new BCD value
    digitalWrite(this->latch, LOW);
    digitalWrite(this->latch, HIGH);
  }
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display off                               */
/*  O : /                                                   */
/************************************************************/
void CD4511::noDisplay()
{
  if(this->blank > -1)
    digitalWrite(this->blank, LOW);
}
