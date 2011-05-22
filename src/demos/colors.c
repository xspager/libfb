#include "../lib/libfb.h"

//void fill_box(int,int,int,int, unsigned char);

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

/*
void fill_box(int x, int y, int w, int h, unsigned char color)
{
	int cx, cy;
	
	for(cy = x; cy < y+h; cy++)
		for(cx = x; cx < x+w; cx++)
			memset(&((unsigned char *)scr)[x][y], color, w);
}
*/
