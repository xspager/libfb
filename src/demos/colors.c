#include <unistd.h>
#include <stdlib.h>
#include <libfb.h>

int main()
{
	lfb_init();
	
	int i;
	for(i=0;i<0xFF;i++){
		lfb.fillscr(0xFF000000 | i<<17 | i<<9 | i);
		lfb.refresh();
		usleep(20*1000);
	}
//	fill_scr(1);
	return EXIT_SUCCESS;
}
