//
// Created by issa on 12/15/18.
//
#ifndef PROJECT_CLIENTSERVER_H
#define PROJECT_CLIENTSERVER_H
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <strings.h>
#include <cstring>
using namespace std;
// class for the clinet.
class ClientServer {
public:
    // send message from the client to the simulator.
    static string sendMessage(const string &message);
    // set the client.
    static void setClient(string ip, int port);
    ~ClientServer();
};


#endif //PROJECT_CLIENTSERVER_H
