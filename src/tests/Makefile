include ../../Makefile.inc

PROGS = colors test16 test32 fbinfo colorscreen testline example1

all: $(PROGS)

test16: test16.c ../libfb.o
	$(CC) -o test16 test16.c -DBLUE $(CFLAGS)

test32: test32.c ../libfb.o
	$(CC) -o test32 test32.c -DBLUE $(CFLAGS)

fbinfo:	fbinfo.c ../libfb.o
	$(CC) -o fbinfo fbinfo.c $(LIBFB) -lm  $(CFLAGS)

colors:	colors.c ../libfb.o
	$(CC) -o colors colors.c $(LIBFB) -lm $(CFLAGS)

colorscreen:	colorscreen.c ../libfb.o
	$(CC) -o colorscreen colorscreen.c $(LIBFB) -lm $(CFLAGS)

testline:	testline.c ../libfb.o
	$(CC) -o testline testline.c $(LIBFB) -lm $(CFLAGS)

example1:	example1.c ../libfb.o
	$(CC) -o example1 example1.c $(LIBFB) -lm $(CFLAGS) -lfreetype -lz -I/usr/include/freetype2/

clean:
	echo $(RM) $(PROGS)
	$(RM) -f $(PROGS)
