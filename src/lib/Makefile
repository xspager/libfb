include ../../Makefile.inc

all:	libfb.o

libfb.o:	libfb.c libfb.h ../../include/font.h
	$(ECHO) $(CC) -c -o libfb.o libfb.c $(CFLAGS)
	$(CC) -c -o libfb.o libfb.c $(CFLAGS)

clean:
	$(RM) libfb.o
