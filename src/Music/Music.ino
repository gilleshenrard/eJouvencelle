#include "Music.h"
#include "notes.h"

//timer1 values
// (value = 16,000,000 / (prescaler * Hz) - 1) -> must be < 65536 for timer1
// 1/64 notes are chosen because smallest musical increment
#define BPM120 62499 // 32Hz tick (1/64 note at 120 BPM)
#define BPM140 53570 // 37.333Hz tick (1/64 note at 140 BPM)
#define BPM160 46873 // 42.667Hz tick (1/64 note at 160 BPM)

int notes[28]={NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
               NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5,
               NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5 /*suspension*/, NOTE_D5,
               NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5};
int length[28]={2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2};

String mel = "5d4 e f g f e d c d e f g f e d c d e f g f e2 d4 g f e d c";

volatile bool tick = false;
bool toggle1 = true;
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
  
  //clear TCCR1
  TCCR1A = 0;
  TCCR1B = 0;

  //reset counter value +
  //set compare match register for 32 Hz increments
  TCNT1  = 0;
  OCR1A = BPM120;

  // turn on CTC mode
  // + Set CS12, CS11 and CS10 bits for 8 prescaler
  // + enable timer compare interrupt
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);
  TIMSK1 |= (1 << OCIE1A);

  //allow interrupts
  sei();

  Serial.begin(9600);
}

/****************************************************************************/
/*  I : timer1 comparator vector                                            */
/*  P : toggle pin 13 at 32Hz (16Hz full wave)                              */
/*  O : /                                                                   */
/****************************************************************************/
ISR(TIMER1_COMPA_vect){
  digitalWrite(12, HIGH);
  tick = true;
  digitalWrite(12, LOW);
}

/****************************************************************************/
/*  I : /                                                                   */
/*  P : Main loop                                                           */
/*  O : /                                                                   */
/****************************************************************************/
void loop() {
  if(tick)
  {
    tick = false;

      if(!melody.finished())
        melody.onTick(mel);
      else
      {
        Serial.write("finished\n");
        melody.stop();
      }
  }
}
