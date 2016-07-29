math.randomseed(os.time()*10000000)

local ffi = require("ffi")
ffi.cdef[[
unsigned int usleep(unsigned int useconds);
]]

local lfb = require("src.libfb")

local Point = ffi.metatype("Point", {})

lfb.fillscr(0) -- black

local t1 = ffi.new("Point[3]", {Point(10,70), Point(50,160), Point(70,80)})
local t2 = ffi.new("Point[3]", {Point(180,50), Point(150,1), Point(70,180)})
local t3 = ffi.new("Point[3]", {Point(180,150), Point(120,160), Point(130,180)})

lfb.drawtriangle(t1, 1, 0xFF0000)
lfb.drawtriangle(t2, 1, 0x00FF00)
lfb.drawtriangle(t3, 1, 0x0000FF)
