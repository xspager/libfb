include ../../Makefile.inc

all:	libfb.o libfb.so

libfb.o:	libfb.c libfb.h ../../include/font.h
	$(ECHO) $(CC) -c -o libfb.o libfb.c $(CFLAGS)
	$(CC) -c -o libfb.o libfb.c $(CFLAGS)

libfb.so:	libfb.o
	$(CC) -shared -o libfb.so libfb.o

clean:
	$(RM) libfb.o
