#include <czmq.h>
#include <stdio.h>
#include <ctype.h>

typedef struct client {
   char username[20];
   char passwd[20];

}client;

int main(int argc, char **argv)
{
   // server, client 
   //request-response
   
   zsock_t * responder = zsock_new(ZMQ_REP);
   int r = zsock_bind(responder, "tcp://*:5555");
   if (r != 5555)
   {
      printf("Failed to bind to port\n");
      return -1;
   }

    while (true) {

        char *msg = zstr_recv(responder);
        if (!msg) {
            printf("Mensaje nulo recibido, saliendo...\n");
            break;
        }

        if (strcmp(msg, "Low Level") == 0) {
            zstr_send(responder, "Gang");
        } else {
            printf("Mensaje recibido: %s\n", msg);
            zstr_send(responder, "OK");
        }

        free(msg);
    }
   
   zsock_destroy(&responder);
   return 0;
}