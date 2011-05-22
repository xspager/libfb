#include "../lib/libfb.h"

#define YELLOW	0xFFFF00
#define GRAY	0x888888
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define RED	0xFF0000

void main()
{
	int x,y,s;
	
	lfb_init();
	lfb.fillscr(GREEN);	
#if 1
	lfb.fillbox(200,200,500,300,BLUE);
	for(y = 0; y < lfb.height; y+=60)
		lfb.drawline((Point){0,y},(Point){lfb.width,y},1,RED);
	for(y = 0; y < lfb.height; y+=50)
		lfb.drawline((Point){0,y},(Point){lfb.width,y},1,RED);
	for(x = 0; x < lfb.width; x+=100)
		lfb.drawline((Point){x,0},(Point){x,lfb.height},1,BLUE);	
	
	for(s = 10; s < 200; s+=10){
		usleep(20000);
		lfb.fillscr(GREEN);	
	//	lfb.fillbox(100,100,lfb.height,lfb.width/2,YELLOW);
		for(y = 0; y < lfb.height; y+=s)
			lfb.drawline((Point){0,y},(Point){lfb.width,y},1,RED);
		for(x = 0; x < lfb.width; x+=s)
			lfb.drawline((Point){x,0},(Point){x,lfb.height},1,BLUE);
	}

	lfb.drawline((Point){400,50},(Point){50,300},1,YELLOW);
	lfb.drawline((Point){400,50},(Point){750,300},1,YELLOW);
	lfb.drawline((Point){750,300},(Point){400,550},1,YELLOW);
	lfb.drawline((Point){400,550},(Point){50,300},1,YELLOW);
#endif
	Point pol[] = {
		(Point){10,10},
		(Point){100,100},
		(Point){300,400},
		(Point){200,200},
		(Point){800,600},
		(Point){50,400},
		(Point){-1,-1}
	};
	lfb.drawpolygon(pol, 1, GRAY);
	lfb.drawline((Point){0,0},(Point){lfb.width,lfb.height}, 1, RED);
}
