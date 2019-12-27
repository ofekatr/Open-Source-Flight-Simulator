#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include "Command.h"
#include "extractExpression.h"
#include "DataReaderServer.h"
// openServerCommand class.
class OpenServerCommand: public Command {
    // iterator
    vector<string>::iterator &iterator1;
public:
    // constructor
    OpenServerCommand(vector<string>::iterator &iter);
    // do command
    void doCommand(vector<string> &text);
};



#endif //PROJECT_OPENSERVERCOMMAND_H
