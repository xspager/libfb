include ../../Makefile.inc

PROGS = arvre colors fbed game pattern squares fbdemo2 text showpng

all:	$(PROGS)

%:	%.c ../lib/libfb.o
	$(ECHO) $(CC) -o $* $*.c -lpng -lm $(LIBFB) $(CFLAGS)
	$(CC) -o $* $*.c -lm $(LIBFB) $(CFLAGS)

clean:
	$(RM) $(PROGS)
