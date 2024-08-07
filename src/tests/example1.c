/* example1.c                                                      */
/*                                                                 */
/* This small program shows how to print a rotated string with the */
/* FreeType 2 library.                                             */
/* Modified from the the sample from:
   http://freetype.sourceforge.net/freetype2/docs/tutorial/step1.html
   http://freetype.sourceforge.net/freetype2/docs/tutorial/example1.c */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include "../../include/libfb.h"


#define WIDTH   1280
#define HEIGHT  1024


/* origin is the upper left corner */
uint32_t image[HEIGHT][WIDTH];


/* Replace this function with something useful. */

void
draw_bitmap( FT_Bitmap*  bitmap,
             FT_Int      x,
             FT_Int      y)
{
  FT_Int  i, j, p, q;
  FT_Int  x_max = x + bitmap->width;
  FT_Int  y_max = y + bitmap->rows;


  for ( i = x, p = 0; i < x_max; i++, p++ )
  {
    for ( j = y, q = 0; j < y_max; j++, q++ )
    {
      if ( i >= WIDTH || j >= HEIGHT )
        continue;

      image[j][i] |= bitmap->buffer[q * bitmap->width + p];
      //image[j][i] = bitmap->buffer[q * bitmap->width + p];
    }
  }
}


void
show_image( void )
{
	int  i, j;
	uint32_t color;

    lfb.fillscr(BLACK);

    for ( i = 0; i < HEIGHT; i++ ) {
        for ( j = 0; j < WIDTH; j++ ) {
			// ARGB
			color = image[i][j];
        	//if(color) {
			//	//printf("0x%08x\n", color);
			//	color = ((color & 0x000000FF) << 8) + 0xFF000000; // map the blue to green and set alpha to 0xFF
			//}
          	lfb.putpixel(i,j, color);
      	}
    }
}


int
main( int     argc,
      char**  argv )
{
  FT_Library    library;
  FT_Face       face;

  FT_GlyphSlot  slot;
  FT_Matrix     matrix;                 /* transformation matrix */
  //FT_UInt       glyph_index;
  FT_Vector     pen;                    /* untransformed origin  */
  FT_Error      error;

  //char*         filename;
  char*         text;

  double        angle;
  int           target_height;
  int           n, num_chars;

  lfb_init();

  if ( argc != 3 )
  {
    fprintf ( stderr, "usage: %s font sample-text\n", argv[0] );
    exit( 1 );
  }

  //filename      = argv[1];                           /* first argument     */
  text          = argv[2];                           /* second argument    */
  num_chars     = strlen( text );
  angle         = ( 90.0 / 360 ) * 3.14159 * 2;      /* use 25 degrees     */
  target_height = HEIGHT;

  error = FT_Init_FreeType( &library );              /* initialize library */
  /* error handling omitted */

  error = FT_New_Face( library, argv[1], 0, &face ); /* create face object */
  /* error handling omitted */

  /* use 50pt at 100dpi */
  error = FT_Set_Char_Size( face, 70 * 64, 0,
                            100, 0 );                /* set character size */
  /* error handling omitted */

  slot = face->glyph;

  /* set up matrix */
  matrix.xx = (FT_Fixed)( cos( angle ) * 0x10000L );
  matrix.xy = (FT_Fixed)( -sin( angle ) * 0x10000L );
  matrix.yx = (FT_Fixed)( -sin( angle ) * 0x10000L );
  matrix.yy = (FT_Fixed)( cos( angle ) * 0x10000L );

  /* the pen position in 26.6 cartesian space coordinates; */
  /* start at (300,200) relative to the upper left corner  */
  pen.x = 100 * 64;
  pen.y = ( target_height - 100 ) * 64;

  for ( n = 0; n < num_chars; n++ )
  {
    /* set transformation */
    FT_Set_Transform( face, &matrix, &pen );

    /* load glyph image into the slot (erase previous one) */
    error = FT_Load_Char( face, text[n], FT_LOAD_RENDER);
    if ( error )
      continue;                 /* ignore errors */

    /* now, draw to our target surface (convert position) */
    draw_bitmap( &slot->bitmap,
                 slot->bitmap_left,
                 target_height - slot->bitmap_top );

    /* increment pen position */
    pen.x += slot->advance.x;
    pen.y += slot->advance.y;
  }

  show_image();

  FT_Done_Face    ( face );
  FT_Done_FreeType( library );

  return EXIT_SUCCESS;
}

/* EOF */
