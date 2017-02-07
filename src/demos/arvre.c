#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <libfb.h>

#define DEGTORAD(x) (x * M_PI / 180)

void desenha_galhos(Point p1, Color c, float h, float w, int angle, int depth)
{
	Point p2;

	if(depth == 0) return;

	p2.x = p1.x + cos(DEGTORAD(angle)) * depth * 7.0;
	p2.y = p1.y + sin(DEGTORAD(angle)) * depth * 7.0;

	lfb.drawline(p1, p2, 1, c);
	desenha_galhos(p2, c, h, w, angle - 30, depth - 1);
	desenha_galhos(p2, c, h, w, angle + 20, depth - 1);
}

int main(){
	Point root;
	
	//srand(time(NULL));
	
	lfb_init();

	root.x = lfb.width / 2;
	root.y = lfb.height;

	lfb.fillscr(BLACK);
	desenha_galhos(root, GREEN, lfb.height, lfb.width, -90, 10);

	return EXIT_SUCCESS;
}

