/*
	libfb.h
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include "../../include/font.h"

#define YELLOW	0xFFFF00
#define GRAY	0x888888
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define RED	0xFF0000
#define WHITE	0xFFFFFF

#if 0
/* colors 8bpp */
#define BLACK		0
#define BLUE		1
#define GREEN		2
#define CYAN		3
#define RED		4
#define MAGENTA		5
#define BROWN		6
#define WHITE		7		
#define GRAY		8
#define	LIGHT_BLUE	9 
#define	LIGHT_GREEN	10
#define LIGHT_CYAN	11
#define LIGHT_RED	12
#define	LIGHT_MAGENTA	13 
#define YELLOW		14
#define LIGHT_WHITE	15
#endif
typedef unsigned char byte;

typedef struct{
	int x;
	int y;
} Point;

typedef int Color;

typedef struct{
	int width;
	int height;
	int bpp;
	char *data;
} Image;

struct{
	int width;
	int height;
	int bpp;
	void (*init)();
	void (*memset)(void *, unsigned int, size_t);
	void (*fillscr)(Color);
	void (*fillbox)(int, int, int, int, Color);
	void (*drawline)(Point, Point, int, Color);
	void (*drawpolygon)(Point *, int, Color);
	void (*drawsquare)(Point, int, int, int, Color);
	void (*fillsquare)(Point, int, int, Color);
	Image* (*loadPNG)(int);
	int (*drawimage)(Image *, Point);
	void (*setpixel)(int offset, Color);
    void (*putpixel)(int, int, Color);
	void (*draw_char)(char, Color);
	void (*refresh)();
} lfb;

extern byte *src;
