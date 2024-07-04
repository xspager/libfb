/**
	@file libfb.h
*/
#include <stddef.h>

#define YELLOW	0xFFFF00
#define GRAY	0x888888
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define RED		0xFFFF0000
#define WHITE	0xFFFFFFFF
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
extern void lfb_init();

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

// same as fb_bitfield
struct Bitfield {
	int offset;		/* beginning of bitfield	*/
	int length;		/* length of bitfield		*/
	int msb_right;	/* != 0 : Most significant bit is right */
};

/**
	lfb
*/
typedef struct {
	char id[18]; /*!< Framebuffer driver identification string */
	int bytes_per_line;
	int width;
	int height;
	int bpp;
	struct Bitfield red;
	struct Bitfield green;
	struct Bitfield blue;
	struct Bitfield transp;
	void (*memset)(void *dst, unsigned int data, size_t n);
	void (*fillscr)(Color c);
	void (*fillbox)(int, int, int, int, Color);
	void (*drawline)(Point a, Point b, int width, Color c);
	void (*drawpolygon)(Point *, int, Color);
	void (*drawtriangle)(Point[3], int, Color);
	void (*drawsquare)(Point, int, int, int, Color);
	void (*fillsquare)(Point, int, int, Color);
	Image* (*loadPNG)(int);
	int (*drawimage)(Image *, Point);
	void (*setpixel)(int offset, Color);
	void (*putpixel)(int, int, Color);
	void (*draw_char)(char, Color);
	void (*refresh)();
    byte *scr;
} lfb_struct;

extern lfb_struct lfb;
