#include <czmq.h>

int main(int argc, char **argv)
{
   // server, client 
   //request-response
   
   zsock_t * responder = zsock_new(ZMQ_REP);
   zsock_bind(responder, "tcp://localhost:5555");
}