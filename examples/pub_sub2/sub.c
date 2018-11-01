#include <stdio.h>
#include <string.h>

#include <zmq.h>
#include "../zhelper.h"

int main(void)
{

    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    zmq_connect(subscriber, "tcp://127.0.0.1:5556");
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "Hello", strlen("Hello"));

    while(1)
    {
        char* key = s_recv(subscriber);
        char* value = s_recv(subscriber);
        printf("[%s] %s\n", key, value);
        free(key);
        free(value);
    }

    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    return 0;
}
