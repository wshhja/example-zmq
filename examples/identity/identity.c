#include "../zhelper.h"

int main()
{
    void *ctx = zmq_ctx_new();

    void *sink = zmq_socket(ctx, ZMQ_ROUTER);
    zmq_bind(sink, "inproc://example");
    
    // 首先允许0MQ设置身份
    void *anonymous = zmq_socket(ctx, ZMQ_REQ);
    zmq_connect(anonymous, "inproc://example");
    s_send(anonymous, "ROUTER users a generated UUDI");
    s_dump(sink);

    // 设置自己的身份
    void *identified = zmq_socket(ctx, ZMQ_REQ);
    zmq_setsockopt(identified, ZMQ_IDENTITY, "PEER2", 5);
    zmq_connect(identified, "inproc://example");
    s_send(identified, "ROUTER socket uses REQ's socket identity");
    s_dump(sink);

    zmq_close(sink);
    zmq_close(anonymous);
    zmq_close(identified);
    zmq_ctx_destroy(ctx);
    return 0;

}