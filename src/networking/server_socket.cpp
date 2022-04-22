#include "server_socket.hpp"

ServerSocket::ServerSocket() {
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1)
    {
        printf("Server socket creation failed!\n");
    }

    struct sockaddr_in local_address;
    local_address.sin_family = AF_INET;
    local_address.sin_port = htons(SERVER_PORT);
    local_address.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock, (struct sockaddr *)&local_address, sizeof(local_address)) == -1)
    {
        printf("Server socket bind failed!\n");
    }
}


void ServerSocket::receive(char * buffer, size_t buffer_size, struct sockaddr_in *from) {
    unsigned int from_size = sizeof(struct sockaddr_in);
    recvfrom(sock, buffer, buffer_size, 0, (struct sockaddr *)from, &from_size);
}
