
all: rep_server.c req_client.c
	gcc req_client.c -o server.out -lzmq
	gcc rep_server.c -o client.out -lzmq

clean:
	rm *.out

.PHONY: clean
