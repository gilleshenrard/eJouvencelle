#ifndef SEGDISPLAY_H_INCLUDED
#define SEGDISPLAY_H_INCLUDED
#include<Arduino.h>

typedef union
{
	unsigned char display;
	struct
	{
		unsigned char g:1;
		unsigned char f:1;
		unsigned char e:1;
		unsigned char d:1;
		unsigned char c:1;
		unsigned char b:1;
		unsigned char a:1;
    unsigned char dot:1;
	}segments;
}t_display;

class segDisplay
{
	static constexpr t_display numbers[10]={{.display=0b01111110},
                                          {.display=0b00110000}, 
                                          {.display=0b01101101},
                                          {.display=0b01111001},
                                          {.display=0b00110011},
                                          {.display=0b01011011},
                                          {.display=0b01011111},
                                          {.display=0b01110000},
                                          {.display=0b01111111},
                                          {.display=0b01111011}};

	private:
		int dot;
		int a, b, c, d, e, f, g;

	public:
		segDisplay(int a, int b, int c, int d, int e, int f, int g);
		~segDisplay();

		void setup();
		void setPins(int a, int b, int c, int d, int e, int f, int g);
    void setDot(int dot);

		void display(int num);
		void noDisplay();
		void displayDot(bool state=true);
};
#endif
