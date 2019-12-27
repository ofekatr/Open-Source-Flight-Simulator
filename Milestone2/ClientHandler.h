//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_CLIENTHANDLER_H
#define MAILSTONE2_CLIENTHANDLER_H

#include "istream"
#include "ostream"
#include "ConnectionManager.h"

class ClientHandler{
public:
    virtual void handleClient(int sockfd) = 0;
};
#endif //MAILSTONE2_CLIENTHANDLER_H
