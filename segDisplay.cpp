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
/*  I : Matching pin numbers for each segment               */
/*  P : Builds and initialises a new 7-segment display      */
/*      with the matching pin numbers                       */
/*  O : /                                                   */
/************************************************************/
segDisplay::segDisplay(int a, int b, int c, int d, int e, int f, int g)
:pinSet=false, dot=0
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
    self.pins[i]=tmp[i];
    
  pinSet=true;
}

/************************************************************/
/*  I : /                                                   */
/*  P : Sets the display pins as output                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::setup()
{
  if(pinSet)
  {
    for(char i=0 ; i<7 ; i++)
      pinMode(pins[i], OUTPUT);
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
  if(pinSet)
  {
    /*Looks into numbers[] for the right number to display
      Starts from the MSB to the LSB (into numbers[number]), to get the values to assign to segment A to segment G
      Also starts from the pin assigned to segment A, and goes on to the pin assigned to the segment G
      Tests the value of each bit with a '&' operation
      At each step, writes HIGH to the current pin if the result is > 0
      Writes LOW if the result is == 0*/
  
    for(char i=64, j=0 ; i>0 ; i/=2, j++)
    {
      if(segDisplay::numbers[num] & i)
        digitalWrite(segments[j], HIGH);    //if test value != 0 -> true then HIGH
      else
        digitalWrite(segments[j], LOW);     //else, the bit is set to 0, thus the signal is LOW
    }
  }
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the display off                               */
/*  O : /                                                   */
/************************************************************/
void segDisplay::noDisplay()
{
  if(pinSet)
  {
    for(char i=0 ; i<7 ; i++)
      digitalWrite(segments[i], LOW);
  }
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the dot on the display on                     */
/*  O : /                                                   */
/************************************************************/
void segDisplay::displayDot()
{
  if(pinSet)
    digitalWrite(dot, HIGH);
}

/************************************************************/
/*  I : /                                                   */
/*  P : Turns the dot on the display off                    */
/*  O : /                                                   */
/************************************************************/
void segDisplay::noDot()
{
  if(pinSet)
    digitalWrite(dot, LOW);
}
