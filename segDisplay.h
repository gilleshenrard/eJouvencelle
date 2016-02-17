#ifndef SEGDISPLAY_H_INCLUDED
#define SEGDISPLAY_H_INCLUDED
#include<Arduino.h>

class segDisplay
{
	private:
		union segments
		{
			int all[7]={0};

			typedef struct
			{
				int a=0;
				int b=0;
				int c=0;
				int d=0;
				int e=0;
				int f=0;
				int g=0;
			}specific;
		};
		int numbers[3][7]={{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
                    	   {LOW, LOW, HIGH, HIGH, LOW, LOW, LOW},
                    	   {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH}};
		int dot=0;

	public:
		segDisplay();
		~segDisplay();

		void setSeg(int, int, int, int, int, int, int, int);
		void setupPins();

		void displayNumber(int);
		void noDisplay();
		void displayDot();
		void noDot();
};
#endif