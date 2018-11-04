
all: reply_server.c dealer_client.c
	gcc dealer_client.c -o client.out -lzmq
	gcc reply_server.c -o server.out -lzmq

clean:
	rm *.out

.PHONY: clean
