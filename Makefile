all:	lib tests demos

lib:
	$(MAKE) -C src/

tests:
	$(MAKE) -C src/tests/

demos:
	$(MAKE) -C src/demos/

clean:
	$(MAKE) -C src/ clean
	$(MAKE) -C src/tests clean
	$(MAKE) -C src/demos clean
