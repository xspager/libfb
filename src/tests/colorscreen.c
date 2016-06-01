#include <libfb.h>

int main()
{
	int i, w, h;
	int x = 0, y = 0;

	lfb_init();
	w = lfb.width; h = lfb.height;

	for(i = 35; i >= 0; i--){
		lfb.fillbox(x, y, w, h, i*i*1000000);
		x += 10; y += 10;
		w = lfb.width - (x + x); h = lfb.height - (y + y);
	}
	
	return 0;
}
