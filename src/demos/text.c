#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <libfb.h>
#define BUF_LEN	32

void draw_char(char, int);

int char_pos = 0;

int main(int argc, char *argv[])
{
    int i;
    char *text;

	lfb_init();
	lfb.fillscr(BLACK);

    if(argc == 2){
        text = argv[1];

	    for(i = 0; i < strlen(text); i++){
    	    lfb.draw_char(toupper(text[i]), 0x579ce3);
	    }
		lfb.refresh();
	}
	else{
		char buf[BUF_LEN];
		size_t bytes_read = 0;
		do{
			bytes_read = read(STDIN_FILENO, buf, sizeof(char) * BUF_LEN);
			for(i = 0; i < (int) bytes_read; i++){
    	    	lfb.draw_char(toupper(buf[i]), 0x579ce3);
				lfb.refresh();
	    	}
		}while(bytes_read > 0);
	}

	return EXIT_SUCCESS;
}

