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
		unsigned char dot;
		unsigned char a, b, c, d, e, f, g;

	public:
		segDisplay(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned char g);
		~segDisplay();

		void setup();
		void setPins(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned char g);
    void setDot(unsigned char dot);

		void display(unsigned char num);
		void displayOFF();
		void displayDot(bool state=true);
};
#endif
