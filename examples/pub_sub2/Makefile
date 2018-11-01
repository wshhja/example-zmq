
all: pub.c sub.c
	gcc pub.c -o pub.out -lzmq
	gcc sub.c -o sub.out -lzmq

clean:
	rm *.out

.PHONY: clean
