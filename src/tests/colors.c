#include <libfb.h>
#define INC 8

int main()
{
	int color;

	lfb_init();
	for(color = 0; color < 0xFF; color+=INC){
		lfb.fillscr(color << 16);
	}
	for(color = 0; color < 0xFF; color+=INC){
		lfb.fillscr(color << 8);
	}
	for(color = 0; color < 0xFF; color+=INC){
		lfb.fillscr(color);
	}
	return 0;
}
