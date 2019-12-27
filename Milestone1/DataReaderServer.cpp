#include "DataReaderServer.h"
#include "socketSingelton.h"

void DataReaderServer::operator()(int port, int hertz) {
    int setSocket;
    int clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

/* First call to socket() function */
    setSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (setSocket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(setSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(setSocket, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    socketSingelton::instance()->setSocketForServer(accept(setSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen));
    if (socketSingelton::instance()->getSockServer()< 0) {
        perror("ERROR on accept");
        exit(1);
    }
    while (true) {
        /* If connection is established then start communicating */
        bzero(buffer, 1024);
        n = read(socketSingelton::instance()->getSockServer(), buffer, 1024);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        initializeDictionaryMap(splitByComma(buffer));
        updateData();
        sleep(hertz / 1000);
    }
}
// split the value by comma
vector<string> DataReaderServer::splitByComma(char *buffer) {
    vector<string> vec;
    string temp;
    int j = 0;
    while (j < FLIGHT_PARAMETERS) {
        string buff;
        while (*buffer != ',' && *buffer != '\n') {
            buff += *buffer;
            ++buffer;
        }
        ++buffer;
        vec.emplace_back(buff);
        j++;
    }
    return vec;
}
// initialize the dictionaryMap
void DataReaderServer::initializeDictionaryMap(vector<string> vector) {
    useMutex.lock();
    for (int i = 0; i < FLIGHT_PARAMETERS; i++) {
        dictionaryPath::instance()->setValue(pathVector[i], atof(vector[i].c_str()));
    }
    useMutex.unlock();
}
// update the symbol table by the value that we accpet from the server.
void DataReaderServer::updateData() {
    useMutex.lock();
    SymbolTable *symbolTable = SymbolTable::instance();
    BIndingTable *bIndingTable = BIndingTable::instance();
    dictionaryPath *dictionaryPath1 = dictionaryPath::instance();
    for (auto key : symbolTable->getMap()) {
        string path = bIndingTable->getValue(key.first);
        if (dictionaryPath1->getPath(path)) {
            double value = dictionaryPath1->getValue(path);
            symbolTable->setValue(key.first, value);
        }
    }
    useMutex.unlock();
}

