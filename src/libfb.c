#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>

#include "../include/libfb.h"
#include "../include/font.h"
//#define DELTA(x,y) ((x)>(y)?(x-y):(y-x))
#define DELTA(x,y) ((x) - (y))

int fb;
byte *scr;
lfb_struct lfb;

void lfb_memset8(void *, unsigned int, size_t);
void lfb_memset8(void *, unsigned int, size_t);
void lfb_memset16(void *, unsigned int, size_t);
void lfb_memset32(void *, unsigned int, size_t);
void lfb_put_pixel(int, int, Color);

void lfb_fill_scr(Color);
void lfb_draw_line(Point, Point, int, Color);
void lfb_exit_error(char *);
void lfb_fill_box(int x, int y, int w, int h, Color);
void lfb_draw_polygon(Point *, int, Color);
void lfb_draw_triangle(Point[3], int, Color);
void lfb_refresh();
void lfb_draw_char(char, Color);

struct fb_var_screeninfo fb_var_info;
struct fb_fix_screeninfo fb_fix_info;

void lfb_init()
{	
	char *FB_DEV = getenv("FRAMEBUFFER");
	if(FB_DEV == NULL){
		FB_DEV = "/dev/fb0";
	}
	fb = open(FB_DEV, O_RDWR);
	if(fb < 0){
		printf("Can`t open %s %s\n", FB_DEV, strerror(errno));
		fb = open("/dev/graphics/fb0", O_RDWR);
		if(fb < 0)
			lfb_exit_error("Can`t open /dev/graphics/fb0\n");
	}
	
	if(ioctl(fb, FBIOGET_VSCREENINFO, &fb_var_info) == -1) {
		perror("Error reading variable information");
		exit(2);
	}
	if(ioctl(fb, FBIOGET_FSCREENINFO, &fb_fix_info) == -1) {
		perror("Error reading fixed information");
		exit(3);
	}
	
	//printf("type: %i type_aux: %i\n",fb_fix_info.type, fb_fix_info.type_aux);

	// set some constants
	strncpy(lfb.id, fb_fix_info.id, sizeof(lfb.id));
	lfb.bytes_per_line = fb_fix_info.line_length;
	lfb.width = fb_var_info.xres;
	lfb.height = fb_var_info.yres;
	lfb.bpp = fb_var_info.bits_per_pixel;
	mempcpy(&lfb.red, &fb_var_info.red, sizeof(struct Bitfield)); // save a copy
	mempcpy(&lfb.green, &fb_var_info.green, sizeof(struct Bitfield)); // save a copy
	mempcpy(&lfb.blue, &fb_var_info.blue, sizeof(struct Bitfield)); // save a copy
	mempcpy(&lfb.transp, &fb_var_info.transp, sizeof(struct Bitfield)); // save a copy
	lfb.fillbox = &lfb_fill_box;
	lfb.drawpolygon = &lfb_draw_polygon;
	lfb.drawtriangle = &lfb_draw_triangle;
	lfb.fillscr = &lfb_fill_scr;
	lfb.drawline = &lfb_draw_line;
	lfb.refresh = &lfb_refresh;
	lfb.draw_char = &lfb_draw_char;
	lfb.putpixel = &lfb_put_pixel;
	
	switch(lfb.bpp){
		case 8:
			lfb.memset = &lfb_memset8;
			break;
		case 16:
			lfb.memset = &lfb_memset16;
			break;
		case 24:
			// TODO
		case 32:
			lfb.memset = &lfb_memset32;
			break;
	}
	
	//printf("Screen size %dx%d\n", lfb.width, lfb.height);

	scr = (unsigned char *) mmap((void *)fb_fix_info.smem_start, fb_fix_info.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fb, 0);
	scr+= (fb_var_info.xoffset + fb_var_info.yoffset * fb_var_info.xres_virtual) * (fb_var_info.bits_per_pixel >> 3);

    lfb.scr = scr;
}

void lfb_fill_scr(Color c)
{
	lfb.fillbox(0, 0, lfb.width, lfb.height, c);
}

void lfb_fill_box(int x, int y, int w, int h, Color color)
{
	int cy;

	if(x+w > lfb.width) w = lfb.width - x;
	if(y+h > lfb.height) h = lfb.height - y;

	for(cy = y; cy < y + h; cy++)
		lfb.memset((unsigned int *)(scr + ((lfb.bytes_per_line) * cy + x)), color, w);
}

/* Modifyed copy from https://github.com/ssloy/tinyrenderer/wiki/Lesson-1:-Bresenham%E2%80%99s-Line-Drawing-Algorithm
	...lets be honest, I couldn't even implement it correctly :/

   And it was't even corret apparenly even without GCC's -O1 "help"
*/
void lfb_draw_line(Point pa, Point pb, int width, Color color)
{
	bool steep = false;
	int x,y;
	Point *start = &pa, *end = &pb, *tmp;

	if(abs(pa.x - pb.x) < abs(pa.y - pb.y)){
		Point new_start = {.x = pa.y, .y = pa.x};
		Point new_end = {.x = pb.y, .y = pb.x};
		start = &new_start;
		end = &new_end;

		steep = true;
	}

	// with GCC 13.2.0 -O1 and up the swap fails and point to garbage
	if(start->x > end->x){
		tmp = start;
		start = end;
		end = tmp;
	}

	int dx = end->x - start->x;
	int dy = end->y - start->y;
	int derror2 = abs(dy)*2;
	int error2 = 0;
	y = start->y;

	for(x = start->x; x < end->x; x++){
		if (steep){
			lfb.putpixel(y, x, color);
		} else {
			lfb.putpixel(x, y, color);
		}
		error2 += derror2;
		if(error2 > dx) {
			y += (end->y > start->y?1:-1);
			error2 -= dx * 2;
		}
	}

	/*
	int x, y;
	int xl,yl;
	float d;
	int deltaX, deltaY;
	int wi; //, i;

	if(pa.y == pb.y)		// horizontal
		if(pb.x < pa.x)
			lfb_fill_box(pb.x, pb.y-(width>>1), pa.x - pb.x, width, color);
		else
			lfb_fill_box(pa.x, pa.y-(width>>1), pb.x - pa.x, width, color);
	else if(pa.x == pb.x)	// vertical		
		if(pb.y < pa.y)
			lfb_fill_box(pb.x-(width>>1), pb.y, width, pa.y - pb.y, color);
		else
			lfb_fill_box(pa.x-(width>>1), pa.y, width, pb.y - pa.y, color);
	else{
		deltaX = DELTA(pa.x, pb.x);
		deltaY = DELTA(pa.y, pb.y);
		
		if(deltaX && deltaX){
			if(deltaX == deltaY){
				//iX = 1;
				//iY = 1;
			} else if(deltaY > deltaX) {
				d = (float) deltaY / (float) deltaX;
				if(pa.x < pb.x){
					x = pa.x; xl = pb.x;
				} else {
					x = pb.x; xl = pa.x;
				}
				y = pa.y < pb.y ? pa.y : pb.y;
				while(x < xl){
					x++;
					y += d;
					for(wi=0; wi < width; wi++)
						lfb.putpixel(x + wi, y, color);
				}
			} else {	// we will run though y
				d = (float) deltaX / (float) deltaY;
				if(pa.y < pb.y){
					y = pa.y; yl = pb.y;
				} else {
					y = pb.y; yl = pa.y;
				}
				x = pa.x;
				while(y < yl){
					y++;
					x += d;
					for(wi=0; wi < width; wi++)
						lfb.putpixel(x + wi, y, color);
				}
			}
		}
	}
	*/
}

/*
 * Pa	 
 *	   Pb 
 */
//void draw_box(Point )

void lfb_draw_polygon(Point *points, int w, Color c)
{
	Point *p = points;
	
	while(p->x > 0 && p->y > 0 && (p+1)->x > 0 && (p+1)->y > 0){
		lfb.drawline(*p, *(p+1),  w, c);
		p++;
	}
	lfb.drawline(*p, *points,  w, c); // close polygon
}

void lfb_draw_triangle(Point p[3], int w, Color c)
{
	int i;
	for(i = 0; i < 2; i++){
		lfb.drawline(p[i], p[i+1],  w, c);
	}
	lfb.drawline(p[2], p[0],  w, c); // close triangle
}

void lfb_set_box(int x, int y, int w, int h)
{
	int i;

	if(x + w > lfb.width && y + h > lfb.height){
		for(i = y; i < h; i++);
		//	lfb_set_line(
	} 
}

int lfb_comp_point(Point *pa, Point *pb)
{
	if(pa->x == pb->x && pa->y == pb->y) {
		return EXIT_SUCCESS;
	} else {
		return -1;
	}
}

void lfb_add_point(Point *pa, Point *pb, Point *pr)
{
	pr->x = pa->x + pb->x;
	pr->y = pa->y + pb->y;
}

void lfb_exit_error(char *str)
{
	write(1, str, strlen(str));
	exit(1);
}

void lfb_memset8(void *dst, unsigned int b, size_t len){
	memset(dst, b, len);
}

void lfb_memset16(void *dst, unsigned int b, size_t len){
	int i;
	uint16_t *dst_16;
	for(i=0; i < len * 2; i++){
		dst_16 = (uint16_t *) dst + i;
		*dst_16 = (uint16_t)b;
	}
	//memset(dst, b, len*2);
}

void lfb_memset32(void *dst, unsigned int b, size_t len){
	uint32_t *dst_32 = (uint32_t *) dst;
	for(int i = 0; i <= len; i++) {
		*(dst_32 + i) = b;
	}
}

void lfb_put_pixel(int x, int y, Color c){
	lfb.memset(scr + (lfb.bytes_per_line * y) + (x*4), c, 1);
}

void lfb_refresh()
{
	fb_var_info.activate |= FB_ACTIVATE_NOW | FB_ACTIVATE_FORCE;
	fb_var_info.yres_virtual = fb_var_info.yres * 2;
	fb_var_info.yoffset = fb_var_info.yres;
	ioctl(fb, FBIOGET_VSCREENINFO, &fb_var_info);	
}

void lfb_draw_char(char ch, int color)
{
	static int char_pos, line;

	char_pos++;

	int c, l;
	//char **font_char = font[ch];

	switch(ch){
		case '\n':
			line++; char_pos = 0;
			return;
		case '\t':
			char_pos += 4;
			return;
	}
	if(char_pos * 8 >= lfb.width){
		line++;
		char_pos=0;
	}

	if(font[(uint8_t) ch] != NULL){
		//printf("%c", ch);
		for(l = 0; l < 8; l++){
			for(c = 0; c < 8; c++){
				//printf("%c", font[ch][l][c]);
				if(font[(uint8_t)ch][l][c] != ' '){
					lfb.putpixel(c+(char_pos*8),l + (8 * line), color);
				}
			}
			//printf("\n");
		}
	}
}

//void openKB(){}	
