#include <czmq.h>
#include <stdio.h>
#include <ctype.h>

#define flush while(getchar() != '\n')

int main(int argc, char **argv)
{
    char userInput[20] = "";
    // request, response
    zsock_t * requester = zsock_new(ZMQ_REQ);
    if (zsock_connect(requester, "tcp://localhost:5555") != 0) {
        printf("Connection Failed... Exiting.\n");
        return -1;
    }

    zstr_send(requester, "Low Level");
    sleep(1);
    char * reply = zstr_recv(requester);
    if (reply) {
        printf("{server}: %s\n", reply);
    }
    free(reply);
    
 while (strcmp(userInput, "q") != 0)
    {
        printf("Introduce mensaje ('q' para salir): ");
        if (scanf(" %19s", userInput)) {
            flush;
            printf("Mensaje leído del usuario = %s\n", userInput);

            if (zstr_send(requester, userInput) == 0) {
                printf("Enviando mensaje... ");
                char *reply = zstr_recv(requester);
                printf("Respuesta del servidor: %s\n", reply);
                free(reply);
            }
        }
    }

    free(reply);
    zsock_destroy(&requester);
}