include ../../Makefile.inc

PROGS = arvre colors fbed game pattern squares fbdemo2 text showpng

all:	$(PROGS)

%:	%.c ../lib/libfb.o
	$(ECHO) $(CC) -o $* $*.c -lm -lpng $(LIBFB) $(CFLAGS)
	$(CC) -o $* $*.c -lm -lpng $(LIBFB) $(CFLAGS)

clean:
	$(RM) $(PROGS)
