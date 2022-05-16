#ifndef CLIENT_SOCKET_H_
#define CLIENT_SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstring>
#include <stdio.h>


const int SERVER_PORT = 2020;

class ClientSocket {
    int sock;
    struct sockaddr_in server_address;

    public:
        ClientSocket();
        void receive(char * buffer, size_t buffer_size);
        void send(char * buffer, size_t buffer_size);
};

#endif // CLIENT_SOCKET_H_
