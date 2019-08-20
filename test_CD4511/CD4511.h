#ifndef CD4511_H_INCLUDED
#define CD4511_H_INCLUDED
#include<Arduino.h>

class CD4511
{
	private:
		int a, b, c, d, latch, blank, test;

	public:
		CD4511(int a, int b, int c, int d, int latch, int blank=-1, int test=-1);
		~CD4511();

		void setup();

    void setNumber(int num);
		void displayOFF();
		void displayON();
};
#endif
