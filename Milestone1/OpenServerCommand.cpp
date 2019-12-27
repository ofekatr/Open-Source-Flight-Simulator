//
// Created by issa on 12/10/18.
#include "OpenServerCommand.h"


using namespace std;
// constructor.
OpenServerCommand::OpenServerCommand(vector<string>::iterator &iter) : iterator1(iter) {}
// open the server
void OpenServerCommand::doCommand(vector<string> &text) {
    // request for server.
    double port = 0, hertz = 0;
    // advance the iterator.
    iterator1++;
    // extract his value.
    port = extractExpression::extract(iterator1, text)->calculate();
    hertz = extractExpression::extract(iterator1, text)->calculate();
    // opening thread.
    thread threadServer(DataReaderServer(),port,hertz);
    threadServer.detach();
}
