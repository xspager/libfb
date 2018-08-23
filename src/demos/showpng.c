/*
 * Taken from http://zarb.org/~gc/html/libpng.html
 *
 */

/*
 * Copyright 2002-2010 Guillaume Cottenceau.
 *
 * This software may be freely redistributed under the terms
 * of the X11 license.
 *
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#define PNG_DEBUG 3
#include <png.h>

#include <libfb.h>

void abort_(const char * s, ...)
{
	va_list args;
	va_start(args, s);
	vfprintf(stderr, s, args);
	fprintf(stderr, "\n");
	va_end(args);
	abort();
}

int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void read_png_file(char* file_name)
{
	uint8_t  header[8];	// 8 is the maximum size that can be checked

	FILE *fp = fopen(file_name, "rb");

	if (!fp)
		abort_("[read_png_file] File %s could not be opened for reading", file_name);
	
	if ( 8!=fread(header, 1, 8, fp) )
        abort_("[read_png_file] File %s could not read PNG signature bytes", file_name);
	

	
	if (png_sig_cmp(header, 0, 8))
		abort_("[read_png_file] File %s is not recognized as a PNG file", file_name);


	/* initialize stuff */
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if (!png_ptr)
		abort_("[read_png_file] png_create_read_struct failed");

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
		abort_("[read_png_file] png_create_info_struct failed");

	if (setjmp(png_jmpbuf(png_ptr)))
		abort_("[read_png_file] Error during init_io");

	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, 8);

	png_read_info(png_ptr, info_ptr);

	width = png_get_image_width(png_ptr, info_ptr);
	height = png_get_image_height(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);

	if(color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_expand(png_ptr);

	number_of_passes = png_set_interlace_handling(png_ptr);
	png_read_update_info(png_ptr, info_ptr);

	/* read file */
	if (setjmp(png_jmpbuf(png_ptr)))
		abort_("[read_png_file] Error during read_image");

	row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
	for (y=0; y<height; y++)
		row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr,info_ptr));

	png_read_image(png_ptr, row_pointers);

	fclose(fp);
}

void process_file(void)
{
	int bytes_pp = 4;

	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
		bytes_pp = 3;
	else
		if (png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_RGBA)
			abort_("[process_file] color_type of input file must be PNG_COLOR_TYPE_RGBA (%d) (is %d)",
				PNG_COLOR_TYPE_RGBA, png_get_color_type(png_ptr, info_ptr));

	for (y=0; y<height; y++) {
		png_byte* row = row_pointers[y];
		for (x=0; x<width; x++) {
			png_byte* ptr = &(row[x * bytes_pp]);
			lfb.putpixel(x,y, ptr[0] << 16 | ptr[1] << 8 | ptr[2]);
		}
	}
}


int main(int argc, char *argv[])
{
	if (argc != 2)
		abort_("Usage: program_name <file>");

	read_png_file(argv[1]);

	lfb_init();

	process_file();

	return EXIT_SUCCESS;
}

