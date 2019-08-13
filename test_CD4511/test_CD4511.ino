#include "CD4511.h"

CD4511 displ = CD4511(5, 6, 7, 8, 9, 10);
String msg = "", tmp = "";
int nb = 0, blk = 0;

void setup() {
  Serial.begin(9600);
  displ.setup();
}

void loop() {
  if(Serial.available()){
    msg=Serial.readString();

    if(msg.substring(0,2) == "PRT"){
      tmp = msg.substring(4, 4);
      nb = tmp.toInt();
      Serial.write(nb);
      displ.display(nb);
    }
    else if(msg.substring(0,2) == "BLK"){
      blk = !blk;
      if(blk)
        displ.displayON();
      else
        displ.displayOFF();

      Serial.write("Toggling display");
    }
  }
}
