#include "MyParllelServer.h"
#include <cstring>

void MyParllelServer::open(int port, ClientHandler *cH) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    /*this->passingData->sockfd = sockfd;*/
    this->passingData->clientHandler = cH;
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        cout << "error in bind" << endl;
        perror("ERROR on binding");
        exit(1);
    }
    struct sockaddr_in cli_addr;
    int clilen, cliSock;
    listen(sockfd, SOMAXCONN);
    clilen = sizeof(cli_addr);
    cliSock = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    this->passingData->sockfd = cliSock;
    if (cliSock >= 0) {
        this->passingData->sockfd = cliSock;
        pthread_t pthread;
        if (pthread_create(&pthread, nullptr, MyParllelServer::threadManager, passingData) != 0) {
            perror("thread failed");
        }
        cout << "added\n";
        this->threads.push_back(pthread);
    }
    timeval timeout;
    timeout.tv_sec = 30;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    while (true) {
        cliSock = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        this->passingData->sockfd = cliSock;
        if (cliSock < 0) {
            if (errno == EWOULDBLOCK) {
                stop();
                break;
            } else {
                stop();
                break;
            }
        }
        pthread_t pthread;
        if (pthread_create(&pthread, nullptr, MyParllelServer::threadManager, passingData) != 0) {
            perror("thread failed");
        }
        cout << "added\n";
        this->threads.push_back(pthread);
    }

}

void *MyParllelServer::threadManager(void *data) {
    struct dataPass *passingData = (struct dataPass *) data;
    passingData->clientHandler->handleClient(passingData->sockfd);
    //::close(passingData->sockfd);
}

void MyParllelServer::stop() {
    for (unsigned long thread : this->threads) {
        pthread_join(thread, nullptr);
    }
    ::close(sockfd);

}

MyParllelServer::~MyParllelServer() {
    delete (this->passingData);
}

void MyParllelServer::close() {

}
