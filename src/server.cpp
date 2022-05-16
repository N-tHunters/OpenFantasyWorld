#include "networking/server_socket.hpp"


const int MAX_CLIENTS = 100;
const int BUFFER_SIZE = 1024;

struct Client_Endpoint {
    struct sockaddr_in addr;
};

int main(int argc, char** argv) {
    char buffer[BUFFER_SIZE];
    ServerSocket server_socket;

    Client_Endpoint client_endpoints[MAX_CLIENTS];
    uint new_client_id = 0;

    struct sockaddr_in from;

    while(true) {
        memset(buffer, 0, BUFFER_SIZE);
        server_socket.receive(buffer, BUFFER_SIZE, &from);
        if(buffer[0] == 'C') {
            printf("New client wants to connect\n");
            uint client_id = new_client_id;
            new_client_id++;

            memset(buffer, 0, BUFFER_SIZE);
            buffer[0] = 'O';
            buffer[1] = client_id;

            client_endpoints[client_id].addr = from;

            server_socket.send(buffer, BUFFER_SIZE, &from);
        } else if(buffer[0] == 'U') {
            uint client_id = buffer[1];
            printf("Client with id %d wants updates but he wont get it", client_id);
        }
    }
}
