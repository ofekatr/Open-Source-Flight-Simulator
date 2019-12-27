//
// Created by issa on 12/15/18.
//

#include <iostream>
#include "ClientServer.h"
#include "mutex"
#include "socketSingelton.h"
using namespace std;

string massage = "";
int sockfd;
void ClientServer::setClient(string ip, int port) {
    // takes the ip
    const char *ipByChar = ip.c_str();
    // for the socket.
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    // set the ip for the host.
    server = gethostbyname(ipByChar);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    while (true) {
        int c = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
        if (c == 0) {
            break;
        }
    }
    socketSingelton::instance()->setSocketForClient(sockfd);
}
/*
 * function that use to send our message to the simulator to control the plane.
 * accept the message after the update to the path with key word set.
 */
string ClientServer::sendMessage(const string &message) {
    int n = 0;
    massage = message;
    /* Send message to the server */
    n = write(socketSingelton::instance()->getSockClient(), massage.c_str(), massage.length());
    massage = "";
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);

    }
    char buffer[256];
    bzero(buffer, 256);
    n = read(socketSingelton::instance()->getSockClient(), buffer, 255);
    return massage;
}
