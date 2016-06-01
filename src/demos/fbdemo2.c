#include <libfb.h>

#define STRIP_WIDTH	32

#define DELAY 8000

void main()
{
	lfb_init();
	int width = lfb.width;
	int height = lfb.height;
	int color, row, col;
while(1){
	for(color = 0; color < STRIP_WIDTH; color++){
		lfb.fillbox(0,0,width - ((width / STRIP_WIDTH) * color),height, color * color * 1000000);
		lfb.refresh();
		usleep(DELAY);
	}

	for(color = 0; color < STRIP_WIDTH; color++){
		lfb.fillbox(0,0,width, height - ((height / STRIP_WIDTH) * color), color * color * 1000000);
		lfb.refresh();
		usleep(DELAY);
	}
}
}
