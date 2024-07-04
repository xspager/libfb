#include <stdio.h>
#include <stdlib.h>
#include <libfb.h>

int main()
{
	lfb_init();
	
	printf("Listing Informations about FrameBuffer\n");
	printf("\t Framebuffer ID: %s\n", lfb.id);
	printf("\t Resolution %i x %i %ibits, bytes p/ line: %d\n", lfb.width, lfb.height, lfb.bpp, lfb.bytes_per_line);
	//printf("\t Red: %ibits, Green: %ibits, Blue: %ibits, Transparence: %ibits\n", scrinfo.red.length, scrinfo.green.length, scrinfo.blue.length, scrinfo.transp.length);	
	//printf("\t Offsets: Red: %i, Green: %i, Blue: %i, Alpha: %i\n", scrinfo.red.offset, scrinfo.green.offset, scrinfo.blue.offset, scrinfo.transp.offset);

	return EXIT_SUCCESS;
}
