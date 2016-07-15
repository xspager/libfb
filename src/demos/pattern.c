#include <stdlib.h>
#include <libfb.h>

#define YELLOW	0xFFFF00
#define GRAY	0x888888
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define RED	0xFF0000

int main()
{
	//int x,y,s;
	
	lfb_init();

#if 0 
	lfb.fillscr(GREEN);	
	lfb.fillbox(200,200,500,300,BLUE);
	for(y = 0; y < lfb.height; y+=60)
		lfb.drawline((Point){0,y},(Point){lfb.width,y},1,RED);
	for(y = 0; y < lfb.height; y+=50)
		lfb.drawline((Point){0,y},(Point){lfb.width,y},1,RED);
	for(x = 0; x < lfb.width; x+=100)
		lfb.drawline((Point){x,0},(Point){x,lfb.height},1,BLUE);	
#endif	
#if 0 
	for(s = 10; s <= 100; s+=10){
		usleep(20000);
		lfb.fillscr(GREEN);	
	//	lfb.fillbox(100,100,lfb.height,lfb.width/2,YELLOW);
		for(y = 0; y < lfb.height; y+=s)
			lfb.drawline((Point){0,y},(Point){lfb.width,y},1,RED);
		for(x = 0; x < lfb.width; x+=s)
			lfb.drawline((Point){x,0},(Point){x,lfb.height},1,BLUE);
	}
#endif
#if 0
	lfb.drawline((Point){400,50},(Point){50,300},1,YELLOW);
	lfb.drawline((Point){400,50},(Point){750,300},1,YELLOW);
	lfb.drawline((Point){750,300},(Point){400,550},1,YELLOW);
	lfb.drawline((Point){400,550},(Point){50,300},1,YELLOW);
#endif

	Point pol[] = {
		(Point){300,100},
		(Point){500,100},
		(Point){700,300},
		(Point){700,500},
		(Point){500,700},
		(Point){300,700},
		(Point){100,500},
		(Point){100,300},
		(Point){300,100},
		(Point){-1,-1}
	};
	lfb.drawpolygon(pol, 2, YELLOW);
//	lfb.drawline((Point){0,0},(Point){lfb.width,lfb.height}, 1, RED);
//	lfb.drawline((Point){lfb.width,0}, (Point){0,lfb.height}, 1, BLUE);

	return EXIT_SUCCESS;
}
