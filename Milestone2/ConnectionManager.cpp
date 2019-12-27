//
// Created by daniel on 1/7/19.
//

#include "ConnectionManager.h"

string ConnectionManager::readLine() {
    timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    /* Now read server response */
    bzero(this->buffer, 256);
    int n = read(this->sockfd, this->buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    string toSend;
    for(int i = 0; i< strlen(this->buffer)-1;i++){
        if(this->buffer[i] != ' ') {
            toSend += this->buffer[i];
        }
    }
    return toSend;
}

void ConnectionManager::sendLine(string msg) {
    int n;
    n = ::send(sockfd, (char *) msg.c_str(), strlen((char *) msg.c_str()), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);

    }
}
