math.randomseed(os.time()*10000000)

local ffi = require("ffi")
ffi.cdef[[
unsigned int usleep(unsigned int useconds);
]]

local lfb = require("src.libfb")

local Point = ffi.metatype("Point", {})

lfb.fillscr(0x2020FF) -- blue background
lfb.fillbox(0, lfb.height/4*3, lfb.width, lfb.height, 0x00FF00) -- green stripe

local a = Point(lfb.width/2, lfb.height/6*2) 
local b = Point(lfb.width/2, lfb.height/6*5)

lfb.drawline(a, b, 1, 0xFFFF00FF)
