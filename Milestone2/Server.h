#ifndef MAILSTONE2_SERVER_H
#define MAILSTONE2_SERVER_H
 // interface for the server.
#include "ClientHandler.h"
namespace server_side {
    class Server {
    protected:
        struct  dataPass{
            int sockfd;
            ClientHandler *clientHandler;
        };
    public:
        /**
         * to open the server
         * @param port port for the server
         * @param clientHandler
         */
        virtual void open(int port, ClientHandler *clientHandler) = 0;

        /**
         * end the server operation.
         */
        virtual void close() = 0;

        virtual ~Server(){

        }
    };
}
#endif //MAILSTONE2_SERVER_H
