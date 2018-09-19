#include <stdio.h>
#include <string.h>

#include <zmq.h>

int main(void)
{

    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    zmq_connect(subscriber, "tcp://127.0.0.1:5556");
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "A", 1);

    while(1)
    {
        char buffer[128] = {0,};
        zmq_recv(subscriber, buffer, sizeof(buffer), 0);
        printf("get subscriber msg %s\n", buffer);
    }

    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    return 0;
}
