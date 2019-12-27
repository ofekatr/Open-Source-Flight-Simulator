#include "MySerialServer.h"
#include "ConnectionManager.h"
/*
void MySerialServer::open(int port, ClientHandler *clinetHandler) {
    *this->online = true;
    struct sockaddr_in serv_addr, clie_addr;

    this->sockfsd = socket(AF_INET, SOCK_STREAM, 0);

    if (this->sockfsd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(this->sockfsd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    if (listen(this->sockfsd, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    setsockopt(this->sockfsd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    auto f = [&] {
        while (isOnline()) {
            int clilen;
            clilen = sizeof(clie_addr);
            this->newsockfd = accept(this->sockfsd, (struct sockaddr *) &clie_addr, (socklen_t *) &clilen);
            if (newsockfd < 0) {
                if (errno == EWOULDBLOCK) {
                    this->close();
                }
            }
            else if (this->newsockfd >= 0) {
                auto *connectionManager = new ConnectionManager(this->newsockfd);
                clinetHandler->handleClient(connectionManager);
            }
        }
    };
    thread t(f);
    t.join();
}
 */
/*
void MySerialServer::close() {
    *this->online = false;
    if(this->online){
        ::close(this->sockfsd);
        ::close(this->newsockfd);
    }
}

bool MySerialServer::isOnline() {
    return *this->online;
}
*/