#include"segDisplay.h"

display = segDisplay(4, 5, 6, 7, 8, 9, 10);
unsigned long prevTime = millis();
int number = 0;

void setup() {
  display.setup();
  display.display(number);
}

void loop() {
  unsigned long newTime = millis();
  if(newTime-prevTime >= 1000)
  {
    number++;
    number%=10;
    display.display(number);
    prevTime = newTime;
  }
}
