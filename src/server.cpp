#include "networking/server_socket.hpp"


const int MAX_CLIENTS = 100;
const int BUFFER_SIZE = 1024;

struct IP_Endpoint {
    uint32_t address;
    uint8_t port;
};

int main(int argc, char** argv) {
    char buffer[BUFFER_SIZE];
    ServerSocket server_socket;

    IP_Endpoint client_endpoints[MAX_CLIENTS];

    struct sockaddr_in from;

    server_socket.receive(buffer, BUFFER_SIZE, &from);
}
