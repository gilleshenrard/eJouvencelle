#include "segDisplay.h"

/************************************************************/
/*  I : /                                                   */
/*  P : Builds and initialises a new 7-segment display      */
/*  O : /                                                   */
/************************************************************/
segDisplay::segDisplay()
{
  pinSet=false;
  dot=0;

  numbers[0].display=126;
  numbers[1].display=48;
  numbers[2].display=109;
  numbers[3].display=121;
  numbers[4].display=51;
  numbers[5].display=91;
  numbers[6].display=95;
  numbers[7].display=112;
  numbers[8].display=127;
  numbers[9].display=123;
}

/************************************************************/
/*  I : /                                                   */
/*  P :                                                     */
/*  O : /                                                   */
/************************************************************/
segDisplay::~segDisplay()
{}

/************************************************************/
/*  I : /                                                   */
/*  P :                                                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::setupPins()
{
  for(int i=0 ; i<7 ; i++)
    pinMode(pins[i], OUTPUT);
}

/************************************************************/
/*  I : Number to display                                   */
/*  P : Sets the pin values of the display to display the   */
/*    received number                                       */
/*  O : /                                                   */
/************************************************************/
void segDisplay::displayNumber(int Number)
{
  /* Tests, bit by bit, the values defined for each pin into numbers[num].
    Starting from 64 to 0, the test will define if the current bit is true or false,
    then shift to the right*/

  for(unsigned char i=64, j=0 ; i>0 ; i/=2, j++)
    if(numbers[num]&i)
      digitalWrite(segments[j], HIGH);    //if test value != 0 -> true then HIGH
    else
      digitalWrite(segments[j], LOW);     //else, the bit is set to 0, thus the signal is LOW
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display off                               */
/*  O : /                                                   */
/************************************************************/
void segDisplay::noDisplay()
{
  for(i=0 ; i<7 ; i++)
    digitalWrite(segments[i], LOW);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the dot on the display on                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::displayDot()
{
    digitalWrite(dot, HIGH);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the dot on the display off                    */
/*  O : /                                                   */
/************************************************************/
void segDisplay::noDot()
{
    digitalWrite(dot, LOW);
}