#include "segDisplay.h"

segDisplay::segDisplay()
{}

segDisplay::~segDisplay()
{}

void segDisplay::setSeg(int a, int b, int c, int d, int e, int f, int g, int newdot)
{
  segments[0]=a;
  segments[1]=b;
  segments[2]=c;
  segments[3]=d;
  segments[4]=e;
  segments[5]=f;
  segments[6]=g;

  dot=newdot;
}

void segDisplay::setupPins()
{
  for(int i=0 ; i<7 ; i++)
    pinMode(segments[i], OUTPUT);

  pinMode(dot, OUTPUT);
}

void segDisplay::displayNumber(int Number)
{
  for(int i=0 ; i<7 ; i++)
    digitalWrite(segments[i], numbers[Number][i]);
}

void segDisplay::noDisplay()
{
  for(int i=0 ; i<7 ; i++)
    digitalWrite(segments[i], LOW);
}

void segDisplay::displayDot()
{
    digitalWrite(dot, HIGH);
}

void segDisplay::noDot()
{
    digitalWrite(dot, LOW);
}