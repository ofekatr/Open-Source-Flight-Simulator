//
// Created by issa on 12/10/18.
//

#include "DefineVarCommand.h"
#include "ClientServer.h"
#include "mutex"


void DefineVarCommand::doCommand(vector<string> &text) {
    if (*iterator1 == "var") { // if stands on 'var'
        iterator1++;
        //this->allTheMaps->setSymbolTable(*iterator1, 0);
        SymbolTable::instance()->setValue(*iterator1, 0);
    }
    string var = *iterator1; // stands on var name.
    iterator1++; // Now either stands on '=' or on the next command.
    if (*iterator1 == "=") {
        if (*++iterator1 == "bind") {
            // IN SEPARATE function.
            string path = *++iterator1; // Now stands on path.
            // if it's a path and not a var.
            if (!SymbolTable::instance()->atTable(path)){
                path.erase(0, 2);
                path.erase(path.length() - 1, 1);
                BIndingTable::instance()->setValue(var, path);
            }
            else{
                useMutex.lock();
                BIndingTable::instance()->setValue(var, (BIndingTable::instance()->getValue(path)));
                useMutex.unlock();
            }

            iterator1++; // Now stands on the next command.
            return;
        }
        // lock the function
        useMutex.lock();
        // extract the value.
        double value = extractExpression::extract(iterator1, text)->calculate();
        // set the value
        SymbolTable::instance()->setValue(var, value);
        // get the path
        string path = BIndingTable::instance()->getValue(var);
        // if it's now empty we setUp the string to send to the simulator.
        if(path != "") {
            string message = "set " + path + " " + to_string(value) + "\r\n";
            message = ClientServer::sendMessage(message);
        }
        useMutex.unlock();
    }
}

DefineVarCommand::DefineVarCommand(vector<string>::iterator &iterator1) : iterator1(iterator1) {}