#include <stdio.h>

int main(int argc, char *argv[])
{
	
	int i;
	for(i=0; i < 800*600; i++){
		//   
		// RRRR RGGG GGGB BBBB
#if 0
#ifdef RED
		putchar(0x0);	// 0000 0000
		putchar(0xF8);	// 1111 1000
#endif
#ifdef GREEN
		putchar(0xE0);	// 1110 0000
		putchar(0x07);	// 0000 0111
#endif
#ifdef BLUE
		putchar(0x1F);	// 0001 1111
		putchar(0x0);	// 0000 0000
#endif
#endif
#ifdef RED
		putchar(0x0);
		putchar(i << 3 & 0xF8);
#endif
#ifdef GREEN
		putchar(i & 0x7);
		putchar(i & 0x78 >> 3); // 0011 1000
#endif
#ifdef BLUE
		putchar(i & 0x1F);
		putchar(0x0);
#endif
	}
	
}
