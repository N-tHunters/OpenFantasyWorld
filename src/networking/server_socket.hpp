#ifndef SERVER_SOCKET_H_
#define SERVER_SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstring>
#include <stdio.h>


const int SERVER_PORT = 2020;

class ServerSocket {
    int sock;

    public:
        ServerSocket();
        void receive(char * buffer, size_t buffer_size, struct sockaddr_in * from);
        void send(char * buffer, size_t buffer_size, struct sockaddr_in * to);
};

#endif // SERVER_SOCKET_H_
