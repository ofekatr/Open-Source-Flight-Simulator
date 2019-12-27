//
// Created by daniel on 1/7/19.
//

#ifndef EVENDERECH2_CONNECTIONMANAGER_H
#define EVENDERECH2_CONNECTIONMANAGER_H

#include <iosfwd>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>
#include <string.h>
#include <sstream>
#include <vector>

#include <string>

using namespace std;

class ConnectionManager {
    int sockfd;
    char buffer[256];

public:
    ConnectionManager(int soc) : sockfd(soc) {}

    string readLine();

    void sendLine(string msg);


};


#endif //EVENDERECH2_CONNECTIONMANAGER_H