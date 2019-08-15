#include "CD4511.h"

CD4511 displ = CD4511(5, 6, 7, 8, 9, 10);
String msg = "", tmp = "";
int nb = 0, blk = 0;

void setup() {
  Serial.begin(9600);
  displ.setup();
}

void loop() {
  int tmp = LOW;
  digitalWrite(LED_BUILTIN, HIGH);
  
  displ.displayON();

  for(int i=0 ; i<10 ; i++){
    displ.display(i);
    delay(500);
  }
}
