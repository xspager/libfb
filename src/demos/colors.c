#include <stdlib.h>
#include <libfb.h>

int main()
{
	lfb_init();
	
	int i;
	for(i=0;i<0xFFFFFF;i+=32){
		lfb.fillscr(i);
		lfb.refresh();
	}
//	fill_scr(1);
	return EXIT_SUCCESS;
}
