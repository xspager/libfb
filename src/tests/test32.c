#include <stdio.h>

#define WIDTH	1024
#define HEIGHT	768
#define BPP		4	// bytes per pixel 

int main(int argc, char *argv[])
{
	
	int i;
	for(i=0; i < WIDTH*HEIGHT*BPP; i++){
#ifdef RED
		putchar(0);
		putchar(0); // 
		putchar(0xFF);
		putchar(0);
#endif
#ifdef GREEN
		putchar(0);
		putchar(0xFF);
		putchar(0);
		putchar(0);
#endif
#ifdef BLUE
		putchar(0xFF);
		putchar(0);
		putchar(0);
		putchar(0x0);
#endif
	}
	
}
