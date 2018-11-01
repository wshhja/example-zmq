
all: pub.c suball.c suba.c subb.c
	gcc pub.c -o pub.out -lzmq
	gcc suball.c -o suball.out -lzmq
	gcc suba.c -o suba.out -lzmq
	gcc subb.c -o subb.out -lzmq

clean:
	rm *.out

.PHONY: clean
