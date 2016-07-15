#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <libfb.h> 

int main()
{
	int i, x, p;
	int x1, y1, x2, y2;

	lfb_init();
	
	lfb.fillscr(0);
	
	srand(time(NULL));
	
	for(i=0; i < 1000; i++){
		x = (double) rand() * 100 / RAND_MAX;
		p = (double) rand() * 100 / RAND_MAX;
		x1 = x % 100 * (lfb.width / 100);
		x2 = p % 100 * (lfb.width / 100);
		y1 = x * (lfb.height / 100);
		y2 = p * (lfb.height / 100);
		lfb.fillbox(x1,y1,x2,y2,x*p*x*p*x+128);
		lfb.refresh();
		//printf("x = %i, x1 = %i, y1 = %i, x2 = %i, y2 = %i\n", x,x1,y1,x2,y2);
		usleep(2000);
	}
	return EXIT_SUCCESS;
}

