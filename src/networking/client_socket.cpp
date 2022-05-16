#include "client_socket.hpp"


const char* SERVER_ADDR = "127.0.0.1";

ClientSocket::ClientSocket() {
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1)
    {
        printf("Client socket creation failed!\n");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDR);
}


void ClientSocket::receive(char * buffer, size_t buffer_size) {
    unsigned int from_size = sizeof(struct sockaddr_in);
    recvfrom(sock, buffer, buffer_size, 0, (struct sockaddr *)&server_address, &from_size);
}


void ClientSocket::send(char * buffer, size_t buffer_size) {
    unsigned int to_size = sizeof(struct sockaddr_in);
    sendto(sock, buffer, buffer_size, 0, (struct sockaddr *)&server_address, to_size);
}
