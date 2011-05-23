include ../../Makefile.inc

all:	arvre colors fbed game pattern squares fbdemo2 text

%:	%.c ../lib/libfb.o
	$(ECHO) $(CC) -o $* $*.c -lm $(LIBFB) -ggdb -DDELAY
	$(CC) -o $* $*.c -lm $(LIBFB) -ggdb -DDELAY

