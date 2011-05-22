include ../../Makefile.inc

PROGS = colors test16 test32 fbinfo colorscreen testline

all: $(PROGS)

test16: test16.c
	$(CC) -o test16 test16.c -DBLUE

test32: test32.c
	$(CC) -o test32 test32.c -DBLUE

fbinfo:	fbinfo.c
	$(CC) -o fbinfo fbinfo.c $(LIBFB) -lm

colors:	colors.c
	$(CC) -o colors colors.c $(LIBFB) -lm

colorscreen:	colorscreen.c
	$(CC) -o colorscreen colorscreen.c $(LIBFB) -lm

testline:	testline.c
	$(CC) -o testline testline.c $(LIBFB) -lm

clean:
	echo $(RM) $(PROGS)
	$(RM) $(PROGS)
