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
	static const t_display numbers[10]={{.display=0b1111110},
						{.display=0b0110000}, 
						{.display=0b1101101},
						{.display=0b1111001},
						{.display=0b0110011},
						{.display=0b1011011},
						{.display=0b1011111},
						{.display=0b1110000},
						{.display=0b1111111},
						{.display=0b1111001}};

	private:
		bool pinSet;
		int dot;
		int pins[7];

	public:
		segDisplay();
		~segDisplay();

		void setPins(int a, int b, int c, int d, int e, int f, int g);
		void pushPins();

		void displayNumber(int num);
		void noDisplay();
		void displayDot();
		void noDot();
};
#endif
