include ../../Makefile.inc

all:	arvre colors fbed game pattern squares fbdemo2 text

%:	%.c ../lib/libfb.o
	$(ECHO) $(CC) -o $* $*.c -lm $(LIBFB) $(CFLAGS)
	$(CC) -o $* $*.c -lm $(LIBFB) $(CFLAGS)

