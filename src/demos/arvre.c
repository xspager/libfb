#include "../lib/libfb.h"
#include <stdlib.h>

#define BLACK	0x0
#define GREEN	0x00FF00
#define RED	0xFF0000
#define	CYAN	0x00FFFF

void desenha_galhos(Point, Color, Color, Color);

int main(){
	Point a = {400,600};
	Point b = {400,550};
	
	srand(time(NULL));
	
	lfb_init();

	while(1){
		lfb.fillscr(BLACK);

		desenha_galhos(b, RED, GREEN, CYAN);
#ifdef WAIT
		sleep(10);
#endif
	}
	return 0;
}

void desenha_galhos(Point p, Color ca, Color cb, Color cc)
{
	Point a,b,c;
	
	a.y = p.y - 65 + p.y / 4800;
//	b.y = p.y - 70 + p.y / 4800;
	c.y = p.y - 75 + p.y / 4800;
	a.y = b.y = c.y = p.y - 70;
	a.x = p.x - rand() % 200 - 1;  
//	b.x = p.x + rand() % 150 - 1;
	c.x = p.x + rand() % 200 + 1;
	
	//printf("b.x = %i\n", b.x);

#ifdef DELAY
	usleep(5000);
#endif
	if(c.y > 0 && a.x > 0 && b.x < 800 && c.x < 800){
#if 1
		lfb.drawline(p, a, 1, ca);
		desenha_galhos(a, ca, cb, cc);
//		lfb.drawline(p, b, 1, cb);
//		desenha_galhos(b, ca, cb, cc);
		lfb.drawline(p, c, 1, cc);
		desenha_galhos(c, ca, cb, cc);
#endif
#if 0
		lfb.drawline(p, a, 3, ca);
//		lfb.drawline(p, b, 3, cb);
		lfb.drawline(p, c, 3, cc);
		desenha_galhos(a, ca, cb, cc);
//		desenha_galhos(b, ca, cb, cc);
		desenha_galhos(c, ca, cb, cc);
#endif
	}
}
