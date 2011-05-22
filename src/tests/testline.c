#include "../lib/libfb.h"

#define BLACK	0x0
#define BLUE	0xFF
#define RED		0x0000FF
#define GRAY	0x888888
#define YELLOW	0xFFFF00

int main(){
	lfb_init();
	
	lfb.fillscr(BLACK);
	lfb.drawline((Point){0,0}, (Point){400,600}, 1, BLUE);
	sleep(1);
	lfb.drawline((Point){800,0}, (Point){400,600}, 1, RED);
	sleep(1);
	lfb.drawline((Point){400,0}, (Point){400,600}, 1, GRAY);
	sleep(1);
	lfb.drawline((Point){0,600}, (Point){400,0}, 1, YELLOW);
}
