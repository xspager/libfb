math.randomseed(os.time()*10000000)

local ffi = require("ffi")
ffi.cdef[[
unsigned int usleep(unsigned int useconds);
]]

local lfb = require("src.lib.libfb")

lfb.fillscr(0x00FF00)

for i = 0, 1000 do 
	x = math.random() * 100
	p = math.random() * 100
	x1 = x % 100 * (lfb.width / 100)
	x2 = p % 100 * (lfb.width / 100)
	y1 = x * (lfb.height / 100)
	y2 = p * (lfb.height / 100)
	lfb.fillbox(x1, x2, y1, y2, ffi.cast("int", math.random()*0x0F0F0F0F))
	lfb.refresh()
	ffi.C.usleep(1*1000)
end

