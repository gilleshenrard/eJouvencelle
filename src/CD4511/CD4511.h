#ifndef CD4511_H_INCLUDED
#define CD4511_H_INCLUDED
#include<Arduino.h>

#define IGNORE_PIN 255

typedef union
{
  char nb;
  struct
  {
    char a:1;
    char b:1;
    char c:1;
    char d:1;
  }pinsval;
}output_u;

class CD4511
{
	private:
		unsigned char a, b, c, d, latch, blank, test, dot;

	public:
		CD4511(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char latch, unsigned char blank = IGNORE_PIN , unsigned char test = IGNORE_PIN, unsigned char dot = IGNORE_PIN);
		~CD4511();

		void setup();
		void display(int num);
		void commit();
		void displayOFF();
		void displayON();
    void displayDot(bool state = true);
};
#endif
