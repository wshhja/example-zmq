#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <zmq.h>

int main(void)
{
    void* context = zmq_ctx_new();
    void* requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://127.0.0.1:5555");

    int num = 0;
    for(;num != 10; num++)
    {
        char buffer[10] = {0,};
        zmq_send(requester, "Hello", strlen("Hello"), 0);
        printf("send msg to server Hello\n");
        zmq_recv(requester, buffer, 10, 0);
        printf("receive msg from server %s\n", buffer);
    }

    zmq_close(requester);
    zmq_ctx_destroy(context);
    return 0;
}
