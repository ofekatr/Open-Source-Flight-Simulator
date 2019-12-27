#include "ConnectCommand.h"
#include "ClientServer.h"
#include "DataReaderServer.h"
#include "extractExpression.h"
#include "CommandExpression.h"
#include "DefineVarCommand.h"

void ConnectCommand::doCommand(vector<string> &text) {
    // Currently stands on connect.
    string ip = "";
    double port = 0;
    ip = *++iterator1; // stands on ip address
    // Now stands on the port expression part.
    iterator1++;
    port =  extractExpression::extract(this->iterator1, text)->calculate();
    ClientServer::setClient(ip,port);
}

ConnectCommand::ConnectCommand(vector<string>::iterator &iterator1) : iterator1(iterator1){}