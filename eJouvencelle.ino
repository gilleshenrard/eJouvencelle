#include"segDisplay.h"

segDisplay display = segDisplay(2, 3, 5, 6, 7, 8, 10);
unsigned long prevTime = millis();
int number = 0, dot=LOW;

void setup() {
  display.setup();
  display.display(number);
  display.setDot(11);
}

void loop() {
  unsigned long newTime = millis();
  if(newTime-prevTime >= 1000)
  {
    dot = !dot;
    display.displayDot(dot);
    number++;
    number%=10;
    display.display(number);
    prevTime = newTime;
  }
}
