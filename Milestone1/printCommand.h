//
// Created by issa on 12/12/18.
//
#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include <vector>
#include <map>
#include "Command.h"

using namespace std;
// class that print the command
class printCommand : public Command {
    // iterator by ref
    vector<string>::iterator &iterator1;
public:
    // print command.
    printCommand(vector<string>::iterator &iterator1);
    // makes the operation.
    void doCommand(vector<string> &text);
};


#endif //PROJECT_PRINTCOMMAND_H
