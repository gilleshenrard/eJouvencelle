#include "CD4511.h"

CD4511 displ = CD4511(5, 6, 7, 8, 9, 10);
String msg = "";
int nb = 0, blk = 0;

void setup() {
  Serial.begin(9600);
  displ.setup();
}

void loop() {
  if(Serial.available()){
    msg=Serial.readString();

    if(msg.substr(0,3) == "PRT"){
      nb = int.parse(msg.substr(5, 5));
      displ.display(nb);
    }
    else if(msg.substr(0,3) == "BLK"){
      blk = !blk;
      if(blk)
        displ.displayON();
      else
        displ.displayOFF();
    }
  }
}
