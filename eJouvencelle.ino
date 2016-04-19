#include"segDisplay.h"

segDisplay display = segDisplay(2, 3, 5, 6, 7, 8, 10);
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
    Serial.write(number);
    number++;
    number%=10;
    prevTime = newTime;
  }
}
