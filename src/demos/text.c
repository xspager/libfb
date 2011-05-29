#include "../lib/libfb.h"

void draw_char(char, int);

int char_pos = 0;

int main(int argc, char *argv[])
{
    int i;
    char *text = "DANIEL O.C. LEMOS SAY: ABRA CADABRA :P XD :D :O  :D :D ....... :D";

    if(argc > 1)
        text = argv[1];

    lfb_init();

    for(i = 0; i < strlen(text); i++){
        lfb.draw_char(text[i], 0x579ce3);
    }
}


