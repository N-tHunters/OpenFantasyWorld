#include <stdlib.h>
#include "networking/client_socket.hpp"


const int BUFFER_SIZE = 1024;


int main(int argc, char **argv) {
    char buffer[BUFFER_SIZE];
    ClientSocket client_socket;

    memset(buffer, 0, BUFFER_SIZE);
    buffer[0] = 'C';
    client_socket.send(buffer, BUFFER_SIZE);

    uint client_id = 0;
    memset(buffer, 0, BUFFER_SIZE);
    client_socket.receive(buffer, BUFFER_SIZE);
    if(buffer[0] != 'O') {
        printf("Error connecting\n");
        exit(-1);
    }

    client_id = buffer[1];
    printf("Client ID: %d\n", client_id);
}
