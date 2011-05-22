CC=gcc
CFLAGS=-ggdb

all:	lib tests demos

lib:
	$(MAKE) -C src/lib

tests:
	$(MAKE) -C src/tests/

demos:
	$(MAKE) -C src/demos/
