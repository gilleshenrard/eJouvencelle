#ifndef CD4511_H_INCLUDED
#define CD4511_H_INCLUDED
#include<Arduino.h>

typedef struct
{
  char a:1;
  char b:1;
  char c:1;
  char d:1;
  char buf:4;
}output_t;

typedef union
{
  char nb;
  output_t pinsval;
}output_u;

class CD4511
{
	private:
		int a, b, c, d, latch, blank, test;

	public:
		CD4511(int a, int b, int c, int d, int latch, int blank = -1 , int test = -1);
		~CD4511();

		void setup();

    void setNumber(int num);
    void commit();
		void displayOFF();
		void displayON();
};
#endif
