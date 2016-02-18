#ifndef SEGDISPLAY_H_INCLUDED
#define SEGDISPLAY_H_INCLUDED
#include<Arduino.h>

typedef union
{
	unsigned char display;
	typedef struct
	{
		int dot:1;
		int a:1;
		int b:1;
		int c:1;
		int d:1;
		int e:1;
		int f:1;
		int g:1;
	}segments;
}t_display;

class segDisplay
{
	static const t_display numbers[10]={{.display=126},
						{.display=48},
						{.display=109},
						{.display=121},
						{.display=51},
						{.display=91},
						{.display=95},
						{.display=112},
						{.display=127},
						{.display=123}};

	private:
		bool pinSet;
		int dot;
		int pins[7];

	public:
		segDisplay();
		~segDisplay();

		void setupPins();

		void displayNumber(int);
		void noDisplay();
		void displayDot();
		void noDot();
};
#endif
