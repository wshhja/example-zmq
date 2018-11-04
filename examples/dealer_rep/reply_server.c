#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <zmq.h>

int main(void)
{
    void *context = zmq_ctx_new();
    void *responder = zmq_socket(context, ZMQ_REP);
    zmq_bind(responder, "tcp://127.0.0.1:5555");

    while(1)
    {
        char buffer[10] = {0,};
        zmq_recv(responder, buffer, sizeof(buffer), 0);
        printf("receive msg from client: %s\n", buffer);
        sleep(1);
        zmq_send(responder, "World", strlen("World"), 0);
        printf("send msg to client: World\n");
    }

    zmq_close(responder);
    zmq_ctx_destroy(context);
    return 0;
}
