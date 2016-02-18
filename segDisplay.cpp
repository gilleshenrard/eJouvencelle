#include "segDisplay.h"

/************************************************************/
/*  I : /                                                   */
/*  P : Builds and initialises a new 7-segment display      */
/*  O : /                                                   */
/************************************************************/
segDisplay::segDisplay()
:pinSet=false, dot=0
{}

/************************************************************/
/*  I : /                                                   */
/*  P : Destroys the current segDisplay                     */
/*  O : /                                                   */
/************************************************************/
segDisplay::~segDisplay()
{}

/************************************************************/
/*  I : /                                                   */
/*  P :                                                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::setPins(int a, int b, int c, int d, int e, int f, int g)
{
  int tmp[7]={a, b, c, d, e, f, g};
  for(char i=0 ; i<7 ; i++)
    self.pins[i]=tmp[i];
}

/************************************************************/
/*  I : /                                                   */
/*  P :                                                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::pushPins()
{
  for(char i=0 ; i<7 ; i++)
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

  for(char i=64, j=0 ; i>0 ; i/=2, j++)
    if(segDisplay::numbers[num] & i)
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
  for(char i=0 ; i<7 ; i++)
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
