all: version_check

version_check: 01/version_check.c
	gcc 01/version_check.c -o exec_version_check -lzmq

clean:
	rm exec*

.PHONY: clean version_check