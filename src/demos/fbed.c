#include "../lib/libfb.h"

#define GREEN	0x00FF00
#define YELLOW	0xFFFF00
#define BLUE	0x0000FF

/*
 *	Draw a yellow box in the midle of the green screen,
 *	padding 200px, suppose 800x600 screen resolution 
 */

main()
{
	lfb_init();
	if(!(lfb.fillscr && lfb.fillbox && lfb.drawline)) printf("?\n");
	lfb.fillscr(GREEN);	
	lfb.fillbox(100,100,600,400,YELLOW);
	lfb.drawline((Point){0,299},(Point){800,299},1,BLUE);	
	lfb.drawline((Point){399,0},(Point){399,600},2,BLUE);	
}
