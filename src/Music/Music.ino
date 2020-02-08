#import "Music.h"
#import "notes.h"

//timer1 values (0x3D08 = 1Hz because (16*10^6) / (1*1024) - 1)
#define BPM120 0xF42 // 4Hz tick (8th note at 120 BPM)

int notes[28]={NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
               NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
               NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5 /*suspension*/, NOTE_D5,
               NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5};
int length[28]={2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2};

volatile bool toggle1 = true;
int BeatsPM = 120;
Music melody = Music(11, notes, 28, length, BeatsPM);


/****************************************************************************/
/*  I : /                                                                   */
/*  P : Setup procedure                                                     */
/*  O : /                                                                   */
/****************************************************************************/
void setup() {
  //stop interrupts
  cli();
  
  //setup melody and pin 13 (test led)
  melody.setup();
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  //set timer1 interrupt at 4Hz
  TCCR1A = 0;
  TCCR1B = 0;

  //reset counter value +
  //set compare match register for 4hz increments
  TCNT1  = 0;
  OCR1A = BPM120;

  // turn on CTC mode
  // + Set prescaler to 1024
  // + enable timer compare interrupt
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  TIMSK1 |= (1 << OCIE1A);

  //allow interrupts
  sei();
}

/****************************************************************************/
/*  I : timer1 comparator vector                                            */
/*  P : toggle pin 13 at 4Hz (2Hz full wave)                                */
/*  O : /                                                                   */
/****************************************************************************/
ISR(TIMER1_COMPA_vect){
  if (toggle1){
    digitalWrite(13,HIGH);
    toggle1 = 0;
  }
  else{
    digitalWrite(13,LOW);
    toggle1 = 1;
  }
}

/****************************************************************************/
/*  I : /                                                                   */
/*  P : Main loop                                                           */
/*  O : /                                                                   */
/****************************************************************************/
void loop() {
  unsigned long newTime = millis();

  melody.start(newTime);
  melody.refresh(newTime);
}
