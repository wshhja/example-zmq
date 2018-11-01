#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <zmq.h>
#include "../zhelper.h"

int main(void)
{
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    zmq_bind(publisher, "tcp://127.0.0.1:5556");

    while (1)
    {
        // 编写两个多部分消息，每个消息都带有一个封包和内容
        s_sendmore(publisher, "hello");
        s_send(publisher, "Hello, We don't want to see this message");
        // 多部分消息是一个整体，要么全收到，要么一个都收不到
        s_sendmore(publisher, "Hello");
        s_send(publisher, "We should see this message");
        sleep(1);
    }

    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}
