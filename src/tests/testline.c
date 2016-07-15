#include <stdlib.h>
#include <unistd.h>
#include <libfb.h>

#define LFB_BLACK	0x0
#define LFB_BLUE	0xFF
#define LFB_RED		0x0000FF
#define LFB_GRAY	0x888888
#define LFB_YELLOW	0xFFFF00

int main(){
	lfb_init();
	
	lfb.fillscr(LFB_BLACK);
	lfb.drawline((Point){0,0}, (Point){400,600}, 1, LFB_BLUE);
	sleep(1);
	lfb.drawline((Point){800,0}, (Point){400,600}, 1, LFB_RED);
	sleep(1);
	lfb.drawline((Point){400,0}, (Point){400,600}, 1, LFB_GRAY);
	sleep(1);
	lfb.drawline((Point){0,600}, (Point){400,0}, 1, LFB_YELLOW);

	return EXIT_SUCCESS;
}
