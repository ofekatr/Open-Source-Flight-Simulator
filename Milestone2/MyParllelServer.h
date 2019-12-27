#include <thread>
#include "Server.h"

#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include "Server.h"
#include "ClientHandler.h"
#include <time.h>
#include <vector>

#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <thread>
#include "Server.h"
#include "Server.h"
class MyParllelServer : public server_side::Server {
    struct dataPass *passingData = new dataPass();
    int sockfd;
    vector <pthread_t> threads;
public:
    void open(int port, ClientHandler *cH);

    void stop();

    void close();

    static void* threadManager (void* data);

    virtual ~MyParllelServer();

};