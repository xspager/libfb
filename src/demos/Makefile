include ../../Makefile.inc

PROGS = arvre colors fbed game pattern squares fbdemo2 text showpng
CFLAGS += -I../../include/

all:	$(PROGS)

%:	%.c ../libfb.o
	$(CC) -o $* $*.c -lm -lpng -lz $(LIBFB) $(CFLAGS) #-static

olive-demo:	olive-demo.c ../libfb.o 
	$(CC) -o olive-demo $(LIBFB) olive-demo.c

clean:
	$(RM) $(PROGS)
