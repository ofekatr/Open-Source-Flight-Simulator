#include <iostream>
#include <fstream>
#include <vector>
#include "Parser.h"
#include "ShuntingYard.h"
#include "lexer.h"
#include "dictionaryPath.h"
#include "SymbolTable.h"
#include "BIndingTable.h"
#include "ClientServer.h"
#include "socketSingelton.h"
#include "expressionList.h"
#define INSTRUCTIONS "test"
using namespace std;
socketSingelton * socketSingelton::socket_instance = NULL;
dictionaryPath *dictionaryPath::map_instance = NULL;
SymbolTable *SymbolTable::map_instance = NULL;
BIndingTable *BIndingTable::map_instance = NULL;
expressionList *expressionList::map_instance = NULL;

int main(int args, char **argv) {
    lexer lexerInstance;
    vector<string> sender = lexerInstance.lexerToTextFile(argv[1]);
    Parser parser(sender);
    parser.createCommand();
    close(socketSingelton::instance()->getSockServer());
    close(socketSingelton::instance()->getSockClient());
}