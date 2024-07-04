include ../../Makefile.inc

PROGS = arvre colors fbed game pattern squares fbdemo2 text showpng olive-demo
CFLAGS += -I../../include/

all:	$(PROGS)

%:	%.c ../libfb.o
	$(CC) -o $* $*.c -lm -lpng -lz $(LIBFB) $(CFLAGS) #-static

clean:
	$(RM) $(PROGS)
