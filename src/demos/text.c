#include "../../include/font.h"
#include "../lib/libfb.h"

void draw_char(char, int);

int char_pos = 0;

int main(int argc, char *argv[])
{
    int i;
    char *text = "DANIEL O.C. LEMOS SAY: ABRA CADABRA";

    if(argc == 2)
        text = argv[1];

    lfb_init();

    for(i = 0; i < strlen(text); i++){
        draw_char(text[i], 0x579ce3);
    }
}

void draw_char(char ch, int color)
{
    char_pos++;

    int c, l;
    //char **font_char = font[ch];

    if(font[ch] != NULL){
        //printf("%c", ch);
        for(l = 0; l < 8; l++){
            for(c = 0; c < 8; c++){
                //printf("%c", font[ch][l][c]);
                if(font[ch][l][c] != ' '){
                    lfb.putpixel(c+(char_pos*8),l+8, color);
                }
                 
            }
            //printf("\n");
        }
    }
}
