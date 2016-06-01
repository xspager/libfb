#include <libfb.h>

void main()
{
	lfb_init();
	
	int i,c;
	for(i=0;i<0xFFFFFF;i+=32){
		lfb.fillscr(i);
		lfb.refresh();
	}
//	fill_scr(1);
}
