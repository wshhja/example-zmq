all: version_check req_rep

version_check: 01/version_check.c
	gcc 01/version_check.c -o version_check.out -lzmq

req_rep: 02/rep_server.c 02/req_client.c
	gcc 02/req_client.c -o req_client.out -lzmq
	gcc 02/rep_server.c -o rep_server.out -lzmq
	
clean:
	rm *.out

.PHONY: clean version_check req_rep