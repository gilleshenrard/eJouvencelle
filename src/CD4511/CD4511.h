#ifndef CD4511_H_INCLUDED
#define CD4511_H_INCLUDED
#include<Arduino.h>

typedef union
{
  char nb;
  struct
  {
    char a:1;
    char b:1;
    char c:1;
    char d:1;
    char buf:4;
  }pinsval;
}output_u;

class CD4511
{
	private:
		int a, b, c, d, latch, blank, test, dot;

	public:
		CD4511(int a, int b, int c, int d, int latch, int blank = -1 , int test = -1, int dot = -1);
		~CD4511();

    void setDot(int dot);
		void setup();
		void display(int num);
		void commit();
		void displayOFF();
		void displayON();
    void displayDot(bool state=true);
};
#endif
