#define OLIVEC_IMPLEMENTATION
#include "../../olive.c"

#include "../../include/libfb.h"

#define WIDTH 1440
#define HEIGHT 900

int main(void)
{
    lfb_init();

    lfb.refresh();
    Olivec_Canvas oc = olivec_canvas((uint32_t *)lfb.scr, lfb.width, lfb.height, lfb.bytes_per_line / 4);
    // Taken from https://upload.wikimedia.org/wikipedia/en/9/9e/Flag_of_Japan.svg
    olivec_fill(oc, 0xFFFFFFFF);
    olivec_circle(oc, lfb.width/2, lfb.height/2, 180, 0xFFBC002D);
    lfb.refresh();
}
