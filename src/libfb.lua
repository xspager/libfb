local ffi = require("ffi")
ffi.cdef[[
typedef struct{
    int x;
    int y;
} Point;

typedef int Color;

typedef struct{
    int width;
    int height;
    int bpp;
    char *data;
} Image;

struct{
    char id[18];
    int width;
    int height;
    int bpp;
    void (*init)();
    void (*memset)(void *, unsigned int, size_t);
    void (*fillscr)(Color);
    void (*fillbox)(int, int, int, int, Color);
    void (*drawline)(Point, Point, int, Color);
    void (*drawpolygon)(Point *, int, Color);
    void (*drawsquare)(Point, int, int, int, Color);
    void (*fillsquare)(Point, int, int, Color);
    Image* (*loadPNG)(int);
    int (*drawimage)(Image *, Point);
    void (*setpixel)(int offset, Color);
    void (*putpixel)(int, int, Color);
    void (*draw_char)(char, Color);
    void (*refresh)();
} lfb;

void lfb_init();
]]

-- FIXME: this path could/should be absolute
local libfb = ffi.load("./src/libfb.so")

libfb.lfb_init()

return libfb.lfb
