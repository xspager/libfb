#include <libfb.h>
#include <stdlib.h>
/*
#define BLACK	0x0
#define GREEN	0x00FF00
#define RED	0xFF0000
#define	CYAN	0x00FFFF
*/
void desenha_galhos(Point, Color, Color);

int main(){
	Point root;
	int i;
	
	srand(time(NULL));
	
	lfb_init();

	root.x = lfb.width / 2;
	root.y = lfb.height;

	for(i=0; i < 10; i++){
		lfb.fillscr(BLACK);

		desenha_galhos(root, RED, GREEN);
#ifdef WAIT
		sleep(10);
#endif
	}
	return 0;
}

void desenha_galhos(Point p, Color ca, Color cb)
{
	Point a, b;
	
	a.y = p.y - 40;
	b.y = p.y - 40;
	
	a.x = p.x - lfb.width/10 >= 0 ? p.x - lfb.width / 10 : 0;
	b.x = p.x + lfb.width/10 < lfb.width ? p.x + lfb.width / 10 : lfb.width;
	
#ifdef DELAY
	usleep(5000);
#endif

	if(p.y > 0 && p.x > 0 && p.x < lfb.width){
		lfb.drawline(p, a, 1, ca);
		lfb.drawline(p, b, 1, cb);
		desenha_galhos(a, ca, cb);
		desenha_galhos(b, ca, cb);
	}
	else return;
}
