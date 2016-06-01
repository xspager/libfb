include ../Makefile.inc

all:	libfb.o libfb.so

libfb.o:	libfb.c ../include/libfb.h ../include/font.h
	$(CC) -c -o libfb.o libfb.c $(CFLAGS)

libfb.so:	libfb.o
	$(CC) -shared -o libfb.so libfb.o

clean:
	$(RM) -f libfb.o libfb.so
