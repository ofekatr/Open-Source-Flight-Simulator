//
// Created by issa on 1/14/19.
//

#ifndef MAILSTONE2_ARGUMENTFORSERVER_H
#define MAILSTONE2_ARGUMENTFORSERVER_H
#include "ClientHandler.h"

/**
 * Used to send arguments for threads.
 */
class ArgumentsForServer {
private:
    ClientHandler *clientHandler;
    int portNum;
    int socketID;
public:

    /* Constructors. */
    ArgumentsForServer(int portNum1, ClientHandler *clientHandler1) {
        clientHandler = clientHandler1;
        portNum = portNum1;
        this->socketID = 0;
    }

    ArgumentsForServer(int portNum1, ClientHandler *clientHandler1, int socket) {
        clientHandler = clientHandler1;
        portNum = portNum1;
        this->socketID = socket;
    }

    /* Getters. */
    int getPortNum() {
        return this->portNum;
    }

    ClientHandler* getClientHandler() {
        return this->clientHandler;
    }

    int getSocketID() const {
        return socketID;
    }
};
#endif //MAILSTONE2_ARGUMENTFORSERVER_H
