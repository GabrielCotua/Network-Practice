#include <czmq.h>

int main(int argc, char **argv)
{
    // request, response
    zsock_t * requester = zsock_new(ZMQ_REQ);
    zsock_connect(requester, "tcp://localhost:5555");
    zstr_send(requester, "Low Level");
    sleep(1);
    char * str = zstr_recv(requester);
    printf("%s!\n", str);

    zsock_destroy(&requester);
}