include ../../Makefile.inc

PROGS = arvre colors fbed game pattern squares fbdemo2 text showpng
CFLAGS += -I../../include/

all:	$(PROGS)

%:	%.c ../libfb.o
	$(CC) -o $* $*.c -lm -lpng $(LIBFB) $(CFLAGS)

clean:
	$(RM) $(PROGS)
