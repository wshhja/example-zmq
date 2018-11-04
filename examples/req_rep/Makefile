
all: rep_server.c req_client.c
	gcc req_client.c -o client.out -lzmq
	gcc rep_server.c -o server.out -lzmq

clean:
	rm *.out

.PHONY: clean
