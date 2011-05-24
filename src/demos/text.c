#include "../../include/font.h"
#include "../lib/libfb.h"

void draw_char(char, int);

int char_pos = 0;

int main(int argc, char *argv[])
{
    int i;
    char text[] = "DANIEL OLIVEIRA COSTA LEMOS TESTE ABRA CADABRA MAGICA";

    lfb_init();

    for(i = 0; i < strlen(text); i++){
        draw_char(text[i], BLUE << i);
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
                    lfb.setpixel(c+(char_pos*8)+((l+8*100)*lfb.width), color);
                }
                 
            }
            //printf("\n");
        }
    }
}
