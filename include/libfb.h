/**
	@file libfb.h
*/
#include <stddef.h>

#define YELLOW	0xFFFF00
#define GRAY	0x888888
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define RED		0xFF0000
#define WHITE	0xFFFFFF
#define BLACK	0x000000

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

/**
	Initialize values and function pointers in lfb.
*/
void lfb_init();

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

/**
	lfb
*/
#ifdef DOXYGEN
typedef struct {
#else
struct {
#endif
	char id[18]; //!< Framebuffer driver identification string
	int width;
	int height;
	int bpp;
	void (*memset)(void *dst, unsigned int data, size_t n);
	void (*fillscr)(Color c);
	void (*fillbox)(int, int, int, int, Color);
	void (*drawline)(Point a, Point b, int width, Color c);
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
