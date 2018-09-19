#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <zmq.h>

int main(void)
{

    void *context = zmq_ctx_new();
    
    void* responder = zmq_socket(context, ZMQ_REP);
    zmq_bind(responder, "tcp://127.0.0.1:5555");

    void *subscriber = zmq_socket(context, ZMQ_SUB);
    zmq_connect(subscriber, "tcp://127.0.0.1:5556");
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "A", strlen("A"));

    int num = 0;
    while(1)
    {
        char msg[256] = {0,};
        zmq_pollitem_t items[] = {
            {responder, 0, ZMQ_POLLIN, 0},
            {subscriber, 0, ZMQ_POLLIN, 0}
        };
        zmq_poll(items, 2, -1);
        if (items[0].revents & ZMQ_POLLIN) 
        {
            memset(msg, 0, sizeof(msg));
            int size = zmq_recv(responder, msg, 255, 0);
            if(size != -1)
            {
                printf("receive request msg %s\n", msg);
                if (num != 10) {
                    zmq_send(responder, "World", strlen("World"), 0);
                    num++;
                }
                sleep(1);
            }
        }
        if (items[1].revents & ZMQ_POLLIN)
        {
            memset(msg, 0, sizeof(msg));
            int size = zmq_recv(subscriber, msg, 255, 0);
            if (size != -1)
            {
                printf("get subscribe msg %s\n", msg);
            }
        }
    }

    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    return 0;
}
