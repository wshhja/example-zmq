all: version_check req_rep pub_sub

version_check: examples/version_check/version_check.c
	gcc examples/version_check/version_check.c -o version_check.out -lzmq

req_rep: examples/req_rep/rep_server.c examples/req_rep/req_client.c
	gcc examples/req_rep/req_client.c -o req.out -lzmq
	gcc examples/req_rep/rep_server.c -o rep.out -lzmq
	
pub_sub: examples/pub_sub/pub.c examples/pub_sub/sub.c examples/pub_sub/sub_a.c examples/pub_sub/sub_b.c
	gcc examples/pub_sub/pub.c -o pub.out -lzmq
	gcc examples/pub_sub/sub.c -o sub.out -lzmq
	gcc examples/pub_sub/sub_a.c -o sub_a.out -lzmq
	gcc examples/pub_sub/sub_b.c -o sub_b.out -lzmq

clean:
	rm *.out

.PHONY: clean version_check req_rep pub_sub
