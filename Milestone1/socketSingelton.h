//
// Created by issa on 12/28/18.
//

#ifndef PROJECT_SOCKETSINGELTON_H
#define PROJECT_SOCKETSINGELTON_H
using namespace std;

class socketSingelton {
    int socketClient;
    int socketServer;
    static socketSingelton *socket_instance;
public:
    // constructor that here we iniliaze the map.
    static inline socketSingelton *instance() {
        if (socket_instance == nullptr) {
            socket_instance = new socketSingelton();
        }
        return socket_instance;
    }
    inline void setSocketForClient(int sock){
        socketClient = sock;
    }
    inline void setSocketForServer(int sock){
        socketServer = sock;
    }
    inline int getSockServer(){
        return socketServer;
    }
    inline int getSockClient(){
        return socketClient;
    }
};


#endif //PROJECT_SOCKETSINGELTON_H
