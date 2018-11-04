#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <zmq.h>
#include "../zhelper.h"

int main(void)
{
    void* context = zmq_ctx_new();
    void* requester = zmq_socket(context, ZMQ_DEALER);
    zmq_connect(requester, "tcp://127.0.0.1:5555");

    int num = 0;
    for(;num != 10; num++)
    {
        char buffer[10] = {0,};
        // DEALER模式需要模拟REQ的请求格式
        s_sendmore(requester, "");
        s_send(requester, "Hello");
        printf("send msg to server Hello\n");
        // DEALER模式可以发送任意数量请求而无需等待响应
        // zmq_recv(requester, buffer, 10, 0);
        // if (strlen(buffer) == 0) {
        //     zmq_recv(requester, buffer, 10, 0);
        //     printf("receive msg from server %s\n", buffer);
        // }
    }

    zmq_close(requester);
    zmq_ctx_destroy(context);
    return 0;
}
