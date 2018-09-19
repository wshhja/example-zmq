#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <zmq.h>

int main(void)
{
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    zmq_bind(publisher, "tcp://127.0.0.1:5556");

    while (1)
    {
        zmq_send(publisher, "A", strlen("A"), 0);
        zmq_send(publisher, "ABC", strlen("ABC"), 0);
        zmq_send(publisher, "B", strlen("B"), 0);
        sleep(1);
    }

    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}
