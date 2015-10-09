CC=gcc
CFLAGS=-ggdb -O3

all:	lib tests demos

lib:
	$(MAKE) -C src/lib

tests:
	$(MAKE) -C src/tests/

demos:
	$(MAKE) -C src/demos/

clean:
	$(MAKE) -C src/lib clean
	$(MAKE) -C src/tests clean
	$(MAKE) -C src/demos clean
