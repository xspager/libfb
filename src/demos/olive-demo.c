#define OLIVEC_IMPLEMENTATION
#include "../../olive.c"

#include "../../include/libfb.h"

#define WIDTH 1440
#define HEIGHT 900

int main(void)
{
    lfb_init();

    lfb.refresh();
    Olivec_Canvas oc = olivec_canvas((uint32_t *)lfb.scr, WIDTH, HEIGHT, 7680/4);
    // Taken from https://upload.wikimedia.org/wikipedia/en/9/9e/Flag_of_Japan.svg
    olivec_fill(oc, 0xFF00FF00);
    olivec_circle(oc, WIDTH/2, HEIGHT/2, 180, 0xFF2D00BC);
    lfb.refresh();
}
